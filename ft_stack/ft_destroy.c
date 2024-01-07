/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:22:39 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 15:51:30 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	destroy_stacks(t_stack **a, t_stack **b, int list_size)
{
	ft_destroy(a);
	if (list_size > 3)
		ft_destroy(b);
}

void	ft_destroy(t_stack **stk)
{
	if (!(!*stk || ft_is_empty(*stk)))
	{
		while (!ft_is_empty(*stk))
			*stk = ft_pop(*stk);
	}
	free (*stk);
	*stk = NULL;
}
