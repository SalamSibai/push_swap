/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:25:40 by ssibai            #+#    #+#             */
/*   Updated: 2023/12/24 19:25:43 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_pop(t_stack *stk)
{
	t_node	*temp;

	if (!stk || !stk->head)
		return (NULL);
	temp = stk->head;
	stk->head = stk->head->previous;
	if (stk->head)
		stk->head->next = NULL;
	update_indexes(stk);
	free (temp);
	return (stk);
}
