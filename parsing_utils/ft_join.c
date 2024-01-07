/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:54:35 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 18:55:50 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

int	skip_spaces(char **args, int i, int j)
{
	while (((args[i][j] == ' ') || ((args[i][j] >= 9) && (args[i][j] <= 13)))
		&& (args[i][j] != '\0'))
		j++;
	return (j);
}

void	ft_copy(char *args, char *list, int *args_idx, int *list_idx)
{
	int	li;
	int	ai;

	li = *list_idx;
	ai = *args_idx;
	while (args[ai] != ' ' && !(args[ai] >= 9 && args[ai] <= 13)
		&& args[ai] != '\0')
	{
		list[li] = args[ai];
		ai ++;
		li ++;
		*list_idx = li;
		*args_idx = ai;
	}
}

char	*copy_to_list(char **args, int arg_num, int list_len)
{
	int		i;
	int		j;
	int		y;
	char	*list;

	i = 0;
	j = 0;
	y = 0;
	list = malloc ((list_len) * sizeof(char *));
	if (!list)
		return (NULL);
	while (j < arg_num)
	{
		y = 0;
		while (args[j][y] != '\0')
		{
			y = skip_spaces(args, j, y);
			ft_copy(args[j], list, &y, &i);
			y = skip_spaces(args, j, y);
			list[i++] = ' ';
		}
		j++;
	}
	list[i] = '\0';
	return (list);
}

int	ft_listlen(char **args)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (args[i] != NULL)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			j = skip_spaces(args, i, j);
			while (args[i][j] != ' ' && !(args[i][j] >= 9 && args[i][j] <= 13)
				&& args[i][j] != '\0')
			{
				j++;
				len++;
			}
			len++;
		}
		i++;
	}
	return (len);
}

char	*ft_join(char **args, int arg_num)
{
	char	*joined;
	int		list_len;

	list_len = ft_listlen(args);
	joined = copy_to_list(args, arg_num, list_len);
	joined[list_len] = '\0';
	return (joined);
}
