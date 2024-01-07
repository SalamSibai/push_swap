/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:08:38 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:36:02 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swaphead_sztwo(t_stack *stk)
{
	stk->head->next = stk->tail;
	stk->tail->previous = stk->head;
	stk->tail->next = NULL;
	stk->head->previous = NULL;
	stk->tail = stk->head;
	stk->head = stk->tail->next;
}
/*

	Swaps head two elements in a single stack

*/

void	ft_swaphead(t_stack *stk, int a)
{
	t_node	*temp;

	if (!stk || !stk->head || !stk->head->previous)
		return ;
	if (a == 1)
		ft_putstr_fd("sa\n", 1);
	else if (a == 0)
		ft_putstr_fd("sb\n", 1);
	else if (a == -1)
		ft_putstr_fd("ss\n", 1);
	temp = stk->head->previous;
	if (ft_length(stk) >= 3)
	{
		stk->head->next = temp;
		stk->head->previous = temp->previous;
		stk->head->previous->next = stk->head;
		temp->previous = stk->head;
		temp->next = NULL;
		stk->head = temp;
	}
	else if (ft_length(stk) == 2)
		ft_swaphead_sztwo(stk);
	update_indexes(stk);
}

/*

	sb and sa together

*/
void	ft_ss(t_stack *a, t_stack *b, int print)
{
	if (print == 1)
		ft_swaphead(a, -1);
	else
		ft_swaphead(a, 5);
	ft_swaphead(b, 5);
}

/*

	pushes head element from one stack to the other
	pa : push from b to a
	pb : push from a to b

*/
void	ft_pushhead(t_stack *dest, t_stack *src, int a)
{
	if (!src || !src->head || !dest)
		return ;
	if (a == 1)
		ft_putstr_fd("pa\n", 1);
	else if (a == 0)
		ft_putstr_fd("pb\n", 1);
	dest = ft_push(dest, src->head->content);
	src = ft_pop(src);
	update_indexes(dest);
	update_indexes(src);
}
