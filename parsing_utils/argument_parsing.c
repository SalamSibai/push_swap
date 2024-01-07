/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:53:13 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 20:22:18 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this file makes sure the argument sent to push swap is placed correctly
	in stack a. first number entered should be on top.

	cases:
	1) numbers that are separated with spaces
	2) multiple arguments that are sent
	3) program also checks if nothing is sent to it
	4) if the argument contains:
		a. characters that are not integers
		b. int > MAX_INT
		c. int < MIN_INT
		d. duplicate numbers
	it returns an error.

	functions that will be needed:
	1) split
	2) atoi (why? because we're reading the characters as chars)

	-what we can do is that, we check the number and compare it to numbers
	already in a list, if it is sorted, we have a boolean that returns true
	as long as everything is still sorted, otherwise as soon as it stops 
	being sorted,
	we return a false and store the index where it is not sorted.
*/

#include "parsing_utils.h"

void	get_error(char **strs, int *num_list)
{
	if (strs)
		free_split(strs);
	if (num_list)
		free(num_list);
	ft_putstr_fd("Error\n", 2);
}

int	str_value(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '+' && str[i] != '-')
		i ++;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			break ;
		i++;
	}
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

int	*get_numlist(char **strs, int *ctr)
{
	int	*nums;
	int	i;

	i = 0;
	nums = malloc((*ctr) * sizeof(int));
	if (!nums)
		return (NULL);
	while (i < (*ctr))
	{
		if (ft_isnotnum(strs[i]) == 1)
		{
			free (nums);
			return (NULL);
		}
		if (ft_atol(strs[i]) > INT_MAX || ft_atol(strs[i]) < INT_MIN)
			return (free (nums), NULL);
		nums[i] = ft_atol(strs[i]);
		i++;
	}
	return (nums);
}

int	check_duplicates(int *num_list, int *ctr)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*ctr) - 1)
	{
		j = i + 1;
		while (j < (*ctr))
		{
			if (num_list[i] == num_list[j])
				return (1);
			j ++;
		}
		i++;
	}
	return (0);
}

int	*ft_validate(char **strs, int joined, int *list_size)
{
	char	**char_list;
	int		*num_list;

	if (joined == 1)
		char_list = ft_split(*strs, list_size);
	else
	{
		char_list = strs;
		if (char_list == NULL)
			return (get_error(NULL, NULL), NULL);
	}
	num_list = get_numlist(char_list, list_size);
	if (!num_list)
		return (get_error(char_list, num_list), NULL);
	if (check_duplicates(num_list, list_size) == 1)
		return (get_error(char_list, num_list), NULL);
	return (free_split (char_list), num_list);
}
