/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:22:45 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:45:10 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stk)
{
	t_node	*itr;

	itr = stk->head;
	while (itr->previous)
	{
		if (itr->content > itr->previous->content)
			return (0);
		itr = itr->previous;
	}
	return (1);
}

void	sort_three(t_stack *stk)
{
	t_node	*max;

	max = find_max(stk);
	if (max == stk->head)
		ft_rot(stk, 1);
	else if (max == stk->head->previous)
		ft_revrot(stk, 1);
	if (stk->head->content > stk->head->previous->content)
		ft_swaphead(stk, 1);
}

void	not_sorted(t_stack *stk, t_node *itr)
{
	int		diff;
	int		i;

	i = 0;
	if ((float)itr->index <= (float)ft_length(stk) / 2.0)
	{
		diff = itr->index + 1;
		while (i < diff)
		{
			ft_rot(stk, 1);
			i ++;
		}
	}
	else
	{
		diff = (ft_length(stk) - 1) - itr->index;
		while (i < diff)
		{
			ft_revrot(stk, 1);
			i++;
		}
	}
}

void	sort_stack(t_stack *stk)
{
	t_node	*itr;

	itr = stk->head;
	while (itr->previous != NULL)
	{
		if (itr->content < itr->previous->content)
			itr = itr->previous;
		else
		{
			not_sorted(stk, itr);
			break ;
		}
	}
}
