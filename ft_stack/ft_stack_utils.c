/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:23 by ssibai            #+#    #+#             */
/*   Updated: 2023/12/24 19:29:10 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_node	*find_max(t_stack *stk)
{
	t_node	*max;
	t_node	*iter;

	max = stk->head;
	iter = stk->head->previous;
	while (iter != NULL)
	{
		if (max->content < iter->content)
			max = iter;
		iter = iter->previous;
	}
	return (max);
}

t_node	*find_min(t_stack *stk)
{
	t_node	*min;
	t_node	*iter;

	min = stk->head;
	iter = stk->head->previous;
	while (iter != NULL)
	{
		if (min->content > iter->content)
			min = iter;
		iter = iter->previous;
	}
	return (min);
}

t_node	*get_node(t_stack *stk, int idx)
{
	t_node	*temp;

	temp = stk->head;
	while (temp->index != idx && temp)
		temp = temp->previous;
	return (temp);
}

int	ft_length(t_stack *stk)
{
	t_node	*temp;
	int		ctr;

	ctr = 0;
	if (!stk || !stk->head)
		return (0);
	temp = stk->head;
	while (temp)
	{
		ctr++;
		temp = temp->previous;
	}
	return (ctr);
}

void	update_indexes(t_stack *stk)
{
	t_node	*temp;
	int		ctr;

	ctr = 0;
	if (!stk || !stk->head)
		return ;
	temp = stk->head;
	while (temp)
	{
		temp->index = ctr;
		ctr++;
		temp = temp->previous;
	}
}
