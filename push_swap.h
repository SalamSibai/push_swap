/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:08:24 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:53:02 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "ft_stack/ft_stack.h"
# include "parsing_utils/parsing_utils.h"

void	ft_push_swap(t_stack *a, t_stack *b, int list_size);
t_stack	*make_stack_a(int *num_list, int list_size);
t_stack	*make_stack_b(t_stack *a, int list_size);

/*******************************************************/
/*******************      utils      *******************/
/*******************************************************/

int		above_median(int src_idx, int t_idx);
int		below_median(int src_idx, int t_idx, t_stack *src, t_stack *t);
int		same_index_weight(int src_idx, int t_idx, t_stack *src, t_stack *t);
int		differet_index_weight(int src_idx, int t_idx, t_stack *src, t_stack *t);
int		smallest_weight(int *weights, int length);
void	place_to_top(t_stack *stk, t_stack *d_stk, int *same_idx, int dest);
int		*find_pos(t_node *src_nd, t_node *dst_nd);
void	same_idx(t_stack *a, t_stack *b, int nd, int dest);
void	differet_index(t_stack *s_stk, t_stack *d_stk, int *idx, int dest);

/*******************************************************/
/*******************     SORTING     *******************/
/*******************************************************/

void	sort_three(t_stack *stk);
t_node	*find_smaller_target(t_node *src, t_stack *dest);
t_node	*find_larger_target(t_node *src, t_stack *dest);
int		calculate_weight(int src_idx, int t_idx, t_stack *src, t_stack *t);
void	sort_in_target(t_stack *src, t_stack *target, int dest);
void	sort_stack(t_stack *stk);
int		sorted(t_stack *stk);
void	to_top_b(int rot, int idx, t_stack *b);
void	to_top_a(int rot, int idx, t_stack *a);

/*******************************************************/
/*******************      MOVES      *******************/
/*******************************************************/

//1) Swapping & pushing
void	ft_swaphead(t_stack *stk, int a);
void	ft_ss(t_stack *a, t_stack *b, int print);
void	ft_pushhead(t_stack *dest, t_stack *src, int a);

//2) Rotating
void	ft_rot(t_stack *stk, int a);
void	ft_rr(t_stack *stka, t_stack *stkb, int print);
void	ft_revrot(t_stack *stk, int a);
void	ft_rrr(t_stack *stka, t_stack *stkb, int print);

#endif