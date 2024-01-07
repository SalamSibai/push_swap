/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:47:42 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 17:33:53 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H

# define PARSING_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

char	*ft_strdup(char *src);
int		ft_isnotnum(char *c);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *str);
char	**ft_split(char *arg, int *list_size);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	free_split(char **p);
char	*ft_join(char **args, int arg_num);
char	**get_charlist(char **args, int ac, int *list_size);
int		is_sorted(int *num_list, int num_ctr);
int		*get_numlist(char **strs, int *ctr);
int		check_duplicates(int *num_list, int *ctr);
void	get_error(char **strs, int *num_list);
int		*ft_validate(char **strs, int joined, int *list_size);
void	ft_putstr_fd(char *s, int fd);

#endif