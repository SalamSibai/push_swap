/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:56:33 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 18:59:17 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*num_list;
	int		list_size;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		num_list = ft_validate(++av, 1, &list_size);
	else
		num_list = ft_validate(get_charlist(++av, ac, &list_size), ac - 1,
				&list_size);
	if (num_list)
	{
		if (is_sorted(num_list, list_size) == 1)
			return (free(num_list), 0);
		a = make_stack_a(num_list, list_size);
		if (list_size > 3)
			b = make_stack_b(a, list_size);
		ft_push_swap(a, b, list_size);
		destroy_stacks(&a, &b, list_size);
	}
	return (0);
}
