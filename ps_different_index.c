/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_different_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:57:33 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:16:30 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief 
/// @param idx idexes of both target and source nodes
/// @param src the source stack
/// @param trg the target stack
/// @param dest if 1, dest is b. if 0 dest is a
void	rrot_both_top(int *idx, t_stack *src, t_stack *trg, int dest)
{
	int	src_idx;
	int	trg_idx;

	src_idx = idx[0];
	trg_idx = idx[1];
	while (src_idx < ft_length(src) && trg_idx < ft_length(trg))
	{
		ft_rrr(src, trg, 1);
		src_idx ++;
		trg_idx ++;
	}
	if (dest == 1)
	{
		if (src_idx == ft_length(src))
			to_top_b(0, trg_idx, trg);
		else if (trg_idx == ft_length(trg))
			to_top_a(0, src_idx, src);
	}
	else
	{
		if (src_idx == ft_length(src))
			to_top_a(0, (ft_length(trg) - trg_idx), trg);
		else if (trg_idx == ft_length(trg))
			to_top_b(0, (ft_length(src) - src_idx), src);
	}
}

void	rot_both_top(int *idx, t_stack *src, t_stack *trg, int dest)
{
	int	src_idx;
	int	trg_idx;

	src_idx = idx[0];
	trg_idx = idx[1];
	while (src_idx > 0 && trg_idx > 0)
	{
		ft_rr(src, trg, 1);
		src_idx --;
		trg_idx --;
	}
	if (dest == 1)
	{
		if (src_idx == 0)
			to_top_b(1, (idx[1] - idx[0]), trg);
		else if (trg_idx == 0)
			to_top_a(1, (idx[0] - idx[1]), src);
	}
	else
	{
		if (src_idx == 0)
			to_top_a(1, (idx[1] - idx[0]), trg);
		else
			to_top_b(1, (idx[0] - idx[1]), src);
	}
}

void	rot_each(t_stack *s_stk, t_stack *d_stk, int *idx, int dest)
{
	if (dest == 1)
	{
		if ((float) idx[0] / (float) ft_length(s_stk) <= 0.5)
			to_top_a(1, idx[0], s_stk);
		else
			to_top_a(0, idx[0], s_stk);
		if ((float) idx[1] / (float) ft_length(d_stk) <= 0.5)
			to_top_b(1, idx[1], d_stk);
		else
			to_top_b(0, idx[1], d_stk);
	}
	else if (dest == 0)
	{
		if ((float) idx[0] / (float) ft_length(s_stk) <= 0.5)
			to_top_b(1, idx[0], s_stk);
		else
			to_top_b(0, idx[0], s_stk);
		if ((float) idx[1] / (float) ft_length(d_stk) <= 0.5)
			to_top_a(1, idx[1], d_stk);
		else
			to_top_a(0, idx[1], d_stk);
	}
}

/// @brief 	places element on top of their respective stacks
/// @param s_stk the stack we'll be pushing from
/// @param d_stk the destination stack
/// @param idx  the pointer containing the indexes of each node:
//				element 0 is from source
/// @param dest if equal 1, then elements are to be pushed
//				from a to b (a is src and b is dest)
void	differet_index(t_stack *s_stk, t_stack *d_stk, int *idx, int dest)
{
	double	s_nd_pos;
	double	d_nd_pos;

	s_nd_pos = (float) idx[0] / (float) ft_length(s_stk);
	d_nd_pos = (float) idx[1] / (float) ft_length(d_stk);
	if (s_nd_pos <= 0.5 && d_nd_pos <= 0.5)
		rot_both_top(idx, s_stk, d_stk, dest);
	else if (s_nd_pos > 0.5 && d_nd_pos > 0.5)
		rrot_both_top(idx, s_stk, d_stk, dest);
	else
		rot_each(s_stk, d_stk, idx, dest);
}
