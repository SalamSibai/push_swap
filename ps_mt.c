/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:00:48 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:46:04 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief find the closest smaller target element in the destination stack
/// @param src source stack
/// @param dest destiantion stack
/// @return the target node
t_node	*find_smaller_target(t_node *src, t_stack *dest)
{
	t_node		*temp;
	t_node		*target;
	long long	diff;
	long long	init_diff;

	temp = dest->head;
	target = temp;
	diff = 9223372036854775807;
	init_diff = 0;
	while (temp)
	{
		if (src->content > temp->content)
		{
			init_diff = (long)src->content - (long)temp->content;
			if (init_diff < diff)
			{
				diff = init_diff;
				target = temp;
			}
		}
		temp = temp->previous;
	}
	if (diff == 9223372036854775807)
		return (find_max(dest));
	return (target);
}

/// @brief find the closest larger element in dest
/// @param src source stack
/// @param dest destination stack
/// @return return the node with the closest larger value
t_node	*find_larger_target(t_node *src, t_stack *dest)
{
	t_node		*temp;
	t_node		*target;
	long long	diff;
	long long	init_diff;

	diff = 9223372036854775807;
	init_diff = 0;
	temp = dest->head;
	target = temp;
	while (temp)
	{
		if (src->content < temp->content)
		{
			init_diff = (long)temp->content - (long)src->content;
			if (init_diff <= diff && init_diff > 0)
			{
				diff = init_diff;
				target = temp;
			}
		}
		temp = temp->previous;
	}
	if (diff == 9223372036854775807)
		return (find_min(dest));
	return (target);
}

/*
	Src is the stack we have the values in
	and target is the one we are looking for targets from 

							|
	posibility 		 		|	weight calculation
	________________________|________________________________________
				
	1) any on index 0		|	weight of that index = 0

	2) any on index 1		|	weight of that index = 1

	3) same index, 			| 	weight equals to the index of both
		above median		|	(rr for both a and b index times)

	4) same index, 			|	for each: 
		below median		|	weight = length - index

	5) same index,			|	rotate up for both index number
		one above one below |	of times

	6) different indexes	|	if (index/stk_length > 1/2)
							|		weight = size - index +1
							|	else
							|		weight = index;
*/
int	calculate_weight(int src_idx, int t_idx, t_stack *src, t_stack *t)
{
	int	total_weight;

	total_weight = 0;
	if (src_idx == t_idx)
		total_weight = same_index_weight(src_idx, t_idx, src, t);
	else
		total_weight = differet_index_weight(src_idx, t_idx, src, t);
	return (total_weight);
}

int	set_smallest_wgt(t_stack *src, t_stack *trg, int *weights, t_node **targets)
{
	int		i;
	t_node	*iter;

	iter = src->head;
	i = 0;
	while (iter)
	{
		targets[i] = find_smaller_target(iter, trg);
		weights[i] = calculate_weight(iter->index,
				targets[i]->index, src, trg);
		i++;
		iter = iter->previous;
	}
	i = smallest_weight(weights, ft_length(src));
	return (i);
}

/// @brief places elements from source to target in order
/// @param src the source stack we're pushing from
/// @param trg the target stack
/// @param dest if == 1, source is a, otherwise source is b
void	sort_in_target(t_stack *src, t_stack *trg, int dest)
{
	int			*weights;
	t_node		**targets;
	t_node		*iter;
	int			i;

	i = 0;
	iter = src->head;
	targets = (t_node **)malloc(ft_length(src) * sizeof(t_node *));
	weights = (int *)malloc(ft_length(src) * sizeof(int));
	if (!targets || !weights)
		return ;
	if (dest == 1)
	{
		i = set_smallest_wgt(src, trg, weights, targets);
		place_to_top(src, trg, find_pos(get_node(src, i), targets[i]), dest);
	}
	else
		place_to_top(src, trg, find_pos(get_node(src, i),
				find_larger_target(iter, trg)), dest);
	free (targets);
	free (weights);
}
