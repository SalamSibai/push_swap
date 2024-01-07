/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:03 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 18:49:46 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	execute_rot(t_stack *a, t_stack *b, char *move)
{
	if (ft_strcmp(move, "ra\n") == 0)
		ft_rot(a, 5);
	else if (ft_strcmp(move, "rb\n") == 0)
		ft_rot(b, 5);
	else if (ft_strcmp(move, "rr\n") == 0)
		ft_rr(a, b, 0);
}

void	execute_revrot(t_stack *a, t_stack *b, char *move)
{
	if (ft_strcmp(move, "rra\n") == 0)
		ft_revrot(a, 5);
	else if (ft_strcmp(move, "rrb\n") == 0)
		ft_revrot(b, 5);
	else if (ft_strcmp(move, "rrr\n") == 0)
		ft_rrr(a, b, 0);
}

void	execute_pushhead(t_stack *a, t_stack *b, char *move)
{
	if (ft_strcmp(move, "pa\n") == 0)
		ft_pushhead(a, b, 5);
	else if (ft_strcmp(move, "pb\n") == 0)
		ft_pushhead(b, a, 5);
}

void	execute_swaphead(t_stack *a, t_stack *b, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		ft_swaphead(a, 5);
	else if (ft_strcmp(move, "sb\n") == 0)
		ft_swaphead(b, 5);
	else if (ft_strcmp(move, "ss\n") == 0)
		ft_ss(a, b, 0);
}
