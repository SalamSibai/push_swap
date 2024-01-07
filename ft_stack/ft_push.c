/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:25:55 by ssibai            #+#    #+#             */
/*   Updated: 2023/12/24 19:26:59 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_push(t_stack *stk, int value)
{
	t_node	*new;
	t_node	*temp;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	if (!stk -> head)
		stk->tail = new;
	new->content = value;
	new->next = NULL;
	new->previous = NULL;
	if (stk->head)
	{
		temp = stk->head;
		new->previous = temp;
		temp->next = new;
	}
	stk->head = new;
	update_indexes(stk);
	return (stk);
}
