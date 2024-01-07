/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:50 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 17:33:29 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	is_sorted(int *num_list, int num_ctr)
{
	int	i;

	i = 0;
	while (i < num_ctr - 1)
	{
		if (num_list[i] > num_list[i + 1])
			return (0);
		i ++;
	}
	return (1);
}
