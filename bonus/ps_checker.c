/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:14:21 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 18:50:18 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"
/// @brief if push instruction, return 1
//			if swap instruction, return 2
//			if rotate operation, return 3
//			if reverse rotate operation, return 4
/// @param inst the line
/// @return if 0, not valid
int	validate_instructions(char *inst)
{
	if (ft_strcmp(inst, "pa\n") == 0
		|| ft_strcmp(inst, "pb\n") == 0)
		return (1);
	if (ft_strcmp(inst, "sa\n") == 0
		|| ft_strcmp(inst, "sb\n") == 0
		|| ft_strcmp(inst, "ss\n") == 0)
		return (2);
	if (ft_strcmp(inst, "ra\n") == 0
		|| ft_strcmp(inst, "rb\n") == 0
		|| ft_strcmp(inst, "rr\n") == 0)
		return (3);
	if (ft_strcmp(inst, "rra\n") == 0
		|| ft_strcmp(inst, "rrb\n") == 0
		|| ft_strcmp(inst, "rrr\n") == 0)
		return (4);
	return (0);
}

void	read_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (validate_instructions(line) == 1)
			execute_pushhead(a, b, line);
		else if (validate_instructions(line) == 2)
			execute_swaphead(a, b, line);
		else if (validate_instructions(line) == 3)
			execute_rot(a, b, line);
		else if (validate_instructions(line) == 4)
			execute_revrot(a, b, line);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		line = get_next_line(0);
	}
	if (sorted(a) == 1 && ft_length(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	int		*num_list;
	int		list_size;
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	else if (ac == 2)
		num_list = ft_validate(++av, 1, &list_size);
	else
		num_list = ft_validate(get_charlist(++av, ac, &list_size),
				ac - 1, &list_size);
	if (num_list)
	{
		if (is_sorted(num_list, list_size) == 1)
			return (free(num_list), 0);
		a = make_stack_a(num_list, list_size);
		b = ft_init_stack();
		read_instructions(a, b);
		destroy_stacks(&a, &b, list_size);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
