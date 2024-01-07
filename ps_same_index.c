/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_same_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:04 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:34:27 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_idx_top(t_stack *src, t_stack *dest, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		ft_rr(src, dest, 1);
		i ++;
	}
}

/// @brief puts element on top of the stack when both 
//			elements are in the lower half
/// @param a the source stack to be pushed to destination
/// @param b the destination stack
/// @param idx index of both elements
/// @param dest if equal 1, then elements are to be pushed 
//				from a to b (s_stk to d_stk)
void	same_idx_bottom_to_b(t_stack *s_stk, t_stack *d_stk, int idx)
{
	int	i;

	i = 0;
	while (i < ft_length(s_stk) - idx)
	{
		ft_revrot(s_stk, 1);
		i++;
	}
	i = 0;
	while (i < ft_length(d_stk) - idx)
	{
		ft_revrot(d_stk, 0);
		i++;
	}
}

void	same_idx_bottom_to_a(t_stack *s_stk, t_stack *d_stk, int idx)
{
	int	i;

	i = 0;
	while (i < ft_length(s_stk) - idx)
	{
		ft_revrot(s_stk, 1);
		i++;
	}
	i = 0;
	while (i < ft_length(d_stk) - idx)
	{
		ft_revrot(d_stk, 0);
		i++;
	}
}

void	same_idx(t_stack *s_stk, t_stack *d_stk, int idx, int dest)
{
	double	s_nd_pos;
	double	d_nd_pos;

	s_nd_pos = (float)idx / (float)ft_length(s_stk);
	d_nd_pos = (float)idx / (float)ft_length(d_stk);
	if (idx == 0)
		return ;
	if (idx == 1)
	{
		if (dest == 0)
			ft_ss(s_stk, d_stk, 1);
		else
			ft_rr(s_stk, d_stk, 1);
	}
	else if (s_nd_pos > 0.5 && d_nd_pos > 0.5)
	{
		if (dest == 1)
			same_idx_bottom_to_b(s_stk, d_stk, idx);
		else
			same_idx_bottom_to_a(s_stk, d_stk, idx);
	}
	else
		same_idx_top(s_stk, d_stk, idx);
}
