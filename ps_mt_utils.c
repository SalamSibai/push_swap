/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mt_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:06:46 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:33:38 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief calcualates the weight to put both the node and its corresponding
//			target to top when they have the same indexes
/// @param src_idx index of source node
/// @param t_idx index of target node
/// @param src source stack
/// @param t target stack
/// @return index of the smallest weight
int	same_index_weight(int src_idx, int t_idx, t_stack *src, t_stack *t)
{
	double	src_weight;
	double	target_weight;

	src_weight = (float)src_idx / (float)ft_length(src);
	target_weight = (float)t_idx / (float)ft_length(t);
	if (src_weight <= 0.5 && target_weight <= 0.5)
		return (src_idx);
	else if (src_weight > 0.5 && target_weight > 0.5)
		return ((ft_length(src) - src_idx) + (ft_length(t) - t_idx));
	else if (src_weight <= 0.5 && target_weight > 0.5)
		return (src_idx);
	else if (src_weight > 0.5 && target_weight <= 0.5)
		return (src_idx);
	return (0);
}

/// @brief calcualates the weight to put both the node and its corresponding
//			target to top when they have different indexes
/// @param src_idx index of source node
/// @param t_idx index of target node
/// @param src source stack
/// @param t target stack
/// @return index of the smallest weight
int	differet_index_weight(int src_idx, int t_idx, t_stack *src, t_stack *t)
{
	double	src_weight;
	double	trg_weight;

	src_weight = (float)src_idx / (float)ft_length(src);
	trg_weight = (float)t_idx / (float)ft_length(t);
	if (src_weight <= 0.5 && trg_weight <= 0.5)
		return (above_median(src_idx, t_idx));
	else if (src_weight > 0.5 && trg_weight > 0.5)
		return (below_median(src_idx, t_idx, src, t));
	else
	{
		if (src_weight > 0.5)
			src_weight = ft_length(src) - src_idx;
		else
			src_weight = src_idx;
		if (trg_weight > 0.5)
			trg_weight = ft_length(t) - t_idx;
		else
			trg_weight = t_idx;
	}
	return (src_weight + trg_weight);
}

/// @brief 	Returns the index of the smallest weight, which corresponds to
//			the index of the smallest target, and the index to the number
//			to be swapped in the source.
/// @param weights the list of weights
/// @param length the length of the stack (or the list)
/// @return index of the smallest weight
int	smallest_weight(int *weights, int length)
{
	int	i;
	int	min;
	int	min_index;

	i = 1;
	min = weights[0];
	min_index = 0;
	while (i < length)
	{
		if (weights[i] < min)
		{
			min = weights[i];
			min_index = i;
		}
		i ++;
	}
	return (min_index);
}

/// @brief 	finds whether the two elements to be pushed 
//			to the top have the same index or not
/// @param src_nd the node in the source stack
/// @param dst_nd the target node in the destination stack
/// @param indexes a pointer the the indexes of both nodes
/// @return returns the value of the index if the indexes are the same
int	*find_pos(t_node *src_nd, t_node *dst_nd)
{
	int	*indexes;
	int	i;

	i = 0;
	indexes = (int *) malloc (sizeof(int) * 2);
	if (!indexes)
		return (NULL);
	if (src_nd->index == dst_nd->index)
	{
		indexes[i++] = src_nd->index;
		indexes[i] = src_nd->index;
	}
	else
	{
		indexes[i++] = src_nd->index;
		indexes[i] = dst_nd->index;
	}
	return (indexes);
}

/// @brief 	places element on top of their respective stacks
/// @param stk the stack we'll be pushing from
/// @param d_stk the destination stack
/// @param idx  the pointer containing the indexes
//				of each node: element 0 is from source
/// @param dest if equal 1, then elements are to be pushed
//				from a to b (a is a and b is b)
void	place_to_top(t_stack *stk, t_stack *d_stk, int *idx, int dest)
{
	if (idx[0] == idx[1])
		same_idx(stk, d_stk, (int)idx[0], dest);
	else
		differet_index(stk, d_stk, idx, dest);
	free (idx);
}
