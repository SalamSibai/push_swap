/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:23:17 by ssibai            #+#    #+#             */
/*   Updated: 2023/12/24 19:23:51 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*stk;

	stk = malloc(sizeof (t_stack));
	if (!stk)
		return (NULL);
	stk->head = NULL;
	return (stk);
}
