/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:09:11 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 16:47:22 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	Rotate up all elements, first element becomes the last

*/
void	ft_rot(t_stack *stk, int a)
{
	if (!stk || !stk->head ||!stk->head->previous)
		return ;
	if (a == 1)
		ft_putstr_fd("ra\n", 1);
	else if (a == 0)
		ft_putstr_fd("rb\n", 1);
	else if (a == -1)
		ft_putstr_fd("rr\n", 1);
	if (ft_length(stk) == 2)
		ft_swaphead(stk, -5);
	else
	{
		stk->tail->previous = stk->head;
		stk->head->next = stk->tail;
		stk->head = stk->head->previous;
		stk->tail = stk->tail->previous;
		stk->head->next = NULL;
		stk->tail->previous = NULL;
		update_indexes(stk);
	}
}

void	ft_rr(t_stack *stka, t_stack *stkb, int print)
{
	if (print == 1)
		ft_rot(stka, -1);
	else
		ft_rot(stka, 5);
	ft_rot(stkb, 5);
}

/*
	Reverse rotate
*/
void	ft_revrot(t_stack *stk, int a)
{
	if (!stk || !stk->head ||!stk->head->previous)
		return ;
	if (a == 1)
		ft_putstr_fd("rra\n", 1);
	else if (a == 0)
		ft_putstr_fd("rrb\n", 1);
	else if (a == -1)
		ft_putstr_fd("rrr\n", 1);
	if (ft_length(stk) == 2)
		ft_swaphead(stk, -5);
	else
	{
		stk->head->next = stk->tail;
		stk->tail->previous = stk->head;
		stk->tail = stk->tail->next;
		stk->tail->previous = NULL;
		stk->head->next->next = NULL;
		stk->head = stk->head->next;
		update_indexes(stk);
	}
}

void	ft_rrr(t_stack *stka, t_stack *stkb, int print)
{
	if (print == 1)
		ft_revrot(stka, -1);
	else
		ft_revrot(stka, 5);
	ft_revrot(stkb, 5);
}
