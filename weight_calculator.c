/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:54:54 by ssibai            #+#    #+#             */
/*   Updated: 2023/12/30 14:33:00 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	above_median(int src_idx, int t_idx)
{
	int	total_weight;

	total_weight = 0;
	if (src_idx < t_idx)
		total_weight = src_idx + (t_idx - src_idx);
	else if (t_idx < src_idx)
		total_weight = t_idx + (src_idx - t_idx);
	return (total_weight);
}

int	below_median(int src_idx, int t_idx, t_stack *src, t_stack *t)
{
	int	total_weight;
	int	src_weight;
	int	trg_weight;

	total_weight = 0;
	src_weight = ft_length(src) - src_idx;
	trg_weight = ft_length(t) - t_idx;
	if (src_weight < trg_weight)
	{
		trg_weight -= src_weight;
		total_weight = src_weight + trg_weight;
	}
	else if (src_weight > trg_weight)
	{
		src_weight -= trg_weight;
		total_weight = src_weight + trg_weight;
	}
	else
		total_weight = src_weight;
	return (total_weight);
}
