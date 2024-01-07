/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:06:03 by ssibai            #+#    #+#             */
/*   Updated: 2024/01/05 20:20:49 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc((ft_strlen(src)+ 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

long	ft_atol(const char *str)
{
	int			i;
	long long	sgn;
	long long	num;

	i = 0;
	num = 0;
	sgn = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == 0)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (2147483648);
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	if (sgn == 1 && num > 2147483647)
		return (num);
	if (sgn == -1 && num * sgn < -2147483648)
		return (sgn * num);
	return (num * sgn);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;
	size_t	cctr;

	i = 0;
	if (s == NULL || start > ft_strlen(s) || s[0] == 0)
		return (NULL);
	slen = ft_strlen(s);
	if (start + len < slen)
		cctr = len;
	else
		cctr = slen - (size_t) start;
	sub = malloc((cctr + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < cctr)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_isnotnum(char *c)
{
	int	i;

	i = 0;
	while ((c[i] == '+' || c[i] == '-') && c[i] != '\0')
		i++;
	if (c[i] == '\0')
		return (1);
	while (c[i] != '\0')
	{
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (1);
		i ++;
	}
	return (0);
}
