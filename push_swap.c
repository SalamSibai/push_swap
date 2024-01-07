/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:57:39 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/02 19:27:01 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	1) psuh list to A
	2) check length:
		if 3: sort 3
		if 2: sort 2
	3) push to B until 3 elements are left in A
		if length of A = 4: 
			push only 1 element
		if more:
			push 2 and find max value
	4) after initial push: find targets for elements in A within B
		The closest smaller value of A in B, and return a pointer to it
	5) after all targets are found, calculate weights and save in an array
	6) Go through our array find the index of the minimum value
		this corresponds to:
		 1- the index of the element in A the index of the element in the target.
	7) once we have both:
		we use the same logic that we calculated the wieghts to, insuring that
		the number of moves remains the same that we calculated.
*/

/// @brief pushes element from stack src to starget
/// @param src source stack
/// @param target destination stack
/// @param dst if 1, being pushed from a to b
void	push_to_dest(t_stack *src, t_stack *dest, int dst)
{
	if (dst == 1)
		ft_pushhead(dest, src, 0);
	else
		ft_pushhead(dest, src, 1);
}

t_stack	*make_stack_b(t_stack *a, int list_size)
{
	t_stack	*b;

	b = ft_init_stack();
	ft_pushhead(b, a, 0);
	if (list_size > 4)
		ft_pushhead(b, a, 0);
	return (b);
}

t_stack	*make_stack_a(int *num_list, int list_size)
{
	t_stack	*a;
	int		i;

	a = ft_init_stack();
	i = list_size - 1;
	while (i >= 0)
	{
		a = ft_push(a, num_list[i]);
		i --;
	}
	free(num_list);
	return (a);
}

void	ft_push_swap(t_stack *a, t_stack *b, int list_size)
{
	if (list_size == 3)
		sort_three(a);
	else if (list_size == 2)
		ft_swaphead(a, 1);
	else
	{
		while (ft_length(a) > 3)
		{
			sort_in_target(a, b, 1);
			push_to_dest(a, b, 1);
		}
		sort_three(a);
		while (ft_length(b) != 0)
		{
			sort_in_target(b, a, 0);
			push_to_dest(b, a, 0);
		}
		sort_stack(a);
	}
}
