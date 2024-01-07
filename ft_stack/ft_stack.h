/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:29:27 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 16:03:29 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H

# define FT_STACK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

/*
	for now: declared list so that we can traverse both ways 
	(method can be changed later)
*/
typedef struct node
{
	int			content;
	int			index;
	struct node	*previous;
	struct node	*next;
}	t_node;

typedef struct stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

/*******************************************************/
/*************      Stack Operations      **************/
/*******************************************************/

t_stack	*ft_init_stack(void);
int		ft_is_empty(t_stack *stk);
void	ft_destroy(t_stack **stk);
t_stack	*ft_push(t_stack *stk, int value);
t_stack	*ft_pop(t_stack *stk);
int		ft_length(t_stack *stk);
void	update_indexes(t_stack *stk);
t_node	*get_node(t_stack *stk, int idx);
t_node	*find_max(t_stack *stk);
t_node	*find_min(t_stack *stk);
void	destroy_stacks(t_stack **a, t_stack **b, int list_size);

#endif
