/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:32:33 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 18:52:26 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	get next line:

	input							process								output
	----->|																|----->
	file																line
			1) char *buff;
			2) read into buffer
			3) look for endl within buffer
			4) if exists, copy till endl to a str (that will be returned)
			5) otherwise, copy to a string that will later be joined with buffer
			6) at the end of each iteration, free the buffer
			7) a pointer should be static, that points to the list that 
			has the copied characters (till the newline obviously)


			cases:
			1) cpy is not empty, and contains a line still
			2) cpy has no new line, so it copies to the buffer again
a. if that buffer has a new line, it strjoins the existing cpy, with
what's in the buffer (till the new line), copies the rest to the cpy,
then frees buffer.
b. if the buffer doesn't have a new line, it str joins everything to cpy,
				then frees buffer.
*/

#include "get_next_line.h"

char	*store_buffer(char *buff, char *cpy, int size, size_t j)
{
	size_t	i;
	char	*temp;

	i = -1;
	if (cpy)
	{
		j = gnl_strlen(cpy);
		temp = cpy;
		cpy = malloc((size_t)size + j + 1);
		if (!cpy)
			return (NULL);
		while (temp [++i] != '\0')
			cpy[i] = temp[i];
		free (temp);
	}
	else
	{
		cpy = malloc((size_t)size + 1);
		if (!cpy)
			return (NULL);
	}
	i = 0;
	while ((int)i < size + 1)
		cpy[j++] = buff[i++];
	return (cpy);
}

/*
	get the line is the function that copies the content of the static variable,
	and returns the string. (the actual logic behind what's going on)
*/

char	*get_the_line(char *cpy, int index)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	str = malloc (index + 2);
	if (!str)
		return (NULL);
	temp = gnl_substr(cpy, index + 1, gnl_strlen(cpy));
	while (i < index + 1)
	{
		str[i] = cpy[i];
		i++;
	}
	str [i] = '\0';
	i = 0;
	while (temp[i] != '\0')
	{
		cpy[i] = temp[i];
		i++;
	}
	cpy [i] = '\0';
	free (temp);
	return (str);
}

/*
	free_buff: whether or not buff should be freed in that specific point of time
	Uses strdup in order to get the line inside cpy, whether we read or not
	this process is helpful when we reach the end of the file
*/
char	*get_end_of_file(char **buff, char **cpy, int free_buff)
{
	char	*str;

	str = NULL;
	if (free_buff == 1)
	{
		str = gnl_strdup(*cpy);
		free (*cpy);
		*cpy = NULL;
		free(*buff);
		*buff = NULL;
		return (str);
	}
	else if (free_buff == 0)
	{
		str = gnl_strdup(*cpy);
		free (cpy);
		cpy = NULL;
		return (str);
	}
	return (NULL);
}
/*
	the read functionality, and what it fills in.
	when index == -1: we did not read a newline in the file
	when index == -2: we reached the end of the file
	any other number: the index where the newline was found
*/

char	*reed(char *buff, char **cpy, int fd, int read_size)
{
	char	*str;
	int		index;

	str = NULL;
	index = 0;
	while (read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size <= 0)
		{
			str = check_cpy(cpy, &buff, 1);
			if (!str)
				return (free(buff), NULL);
			return (str);
		}
		buff[read_size] = '\0';
		*cpy = store_buffer(buff, *cpy, BUFFER_SIZE, 0);
		index = line_checker(*cpy, 1);
		if (index == -2)
			return (get_end_of_file(&buff, cpy, 1));
		if (index != -1)
			return (free(buff), get_the_line(*cpy, index));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*cpy;
	struct s_vars	v;

	v = (struct s_vars){NULL, NULL, 0};
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, v.buff, 0) < 0)
	{
		if (cpy)
			free(cpy);
		cpy = NULL;
		return (NULL);
	}
	v.str = check_cpy(&cpy, &v.buff, 0);
	if (v.str)
		return (v.str);
	v.buff = malloc(BUFFER_SIZE + 1);
	if (!v.buff)
		return (NULL);
	v.str = reed(v.buff, &cpy, fd, 1);
	if (cpy && gnl_strlen(cpy) == 0)
	{
		free(cpy);
		cpy = NULL;
	}
	return (v.str);
}
