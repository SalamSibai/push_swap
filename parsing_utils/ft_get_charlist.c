/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_charlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:53:48 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 18:54:14 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

int	trim_ctr(char *args)
{
	int	i;
	int	s;
	int	n;

	s = 0;
	i = 0;
	n = 0;
	while (args[i] != '\0')
	{
		if ((args[i] == ' ') || (args[i] >= 9 && args[i] <= 13))
		{
			s++;
			i++;
		}
		else
		{
			while (args[i] != ' ' && !(args[i] >= 9 && args[i] <= 13)
				&& args[i] != '\0')
				i++;
			n++;
		}
	}
	if (s == i)
		return (-1);
	return (n);
}

int	num_count(char **args, int ac)
{
	int	ctr;
	int	i;
	int	n;

	ctr = 0;
	i = 0;
	n = 0;
	while (i < ac -1)
	{
		n = trim_ctr(args[i]);
		if (n == -1)
			return (-1);
		ctr += n;
		i++;
	}
	return (ctr);
}

char	**get_charlist(char **args, int ac, int *list_size)
{
	char	**char_list;
	char	*joined;

	char_list = NULL;
	joined = NULL;
	*list_size = num_count(args, ac);
	if (*list_size == -1)
		return (NULL);
	joined = ft_join(args, ac - 1);
	char_list = ft_split(joined, list_size);
	free(joined);
	return (char_list);
}
