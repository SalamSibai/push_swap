/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_different_index_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:08:51 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:09:36 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_top_a(int rot, int idx, t_stack *a)
{
	int	i;

	i = 0;
	if (rot == 1)
	{
		while (i < idx)
		{
			ft_rot(a, 1);
			i ++;
		}
	}
	else
	{
		while (i < ft_length(a) - idx)
		{
			ft_revrot(a, 1);
			i ++;
		}
	}
}

void	to_top_b(int rot, int idx, t_stack *b)
{
	int	i;

	i = 0;
	if (rot == 1)
	{
		while (i < idx)
		{
			ft_rot(b, 0);
			i ++;
		}
	}
	else
	{
		while (i < ft_length(b) - idx)
		{
			ft_revrot(b, 0);
			i ++;
		}
	}
}
