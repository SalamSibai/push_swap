/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:45:55 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 15:46:09 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct s_vars
{
	char		*buff;
	char		*str;
	int			read_size;
};

char	*get_next_line(int fd);
char	*get_the_line(char *cpy, int index);
char	*store_buffer(char *buff, char *cpy, int size, size_t j);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strdup(const char *src);
int		line_checker(char *line, int reed);
size_t	gnl_strlen(const char *s);
char	*get_end_of_file(char **buff, char **cpy, int free_buff);
char	*check_cpy(char **cpy, char **buff, int after_reedvl);
char	*reed(char *buff, char **cpy, int fd, int read_size);

#endif