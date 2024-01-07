/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:37:39 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 19:41:20 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H

# define PS_CHECKER_H

# include "../push_swap.h"
# include "../get_next_line/get_next_line.h"

/*******************************************************/
/*******************      utils      *******************/
/*******************************************************/

int		ft_strcmp(char *s1, char *s2);

/*******************************************************/
/*******************      MOVES      *******************/
/*******************************************************/

void	execute_rot(t_stack *a, t_stack *b, char *move);
void	execute_revrot(t_stack *a, t_stack *b, char *move);
void	execute_pushhead(t_stack *a, t_stack *b, char *move);
void	execute_swaphead(t_stack *a, t_stack *b, char *move);

#endif