/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 06:38:50 by zatalbi           #+#    #+#             */
/*   Updated: 2025/04/18 12:43:03 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

long	ft_atol(char *str)
{
	long long	num;
	int			sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && num > (num * 10 + (*str - 48)))
			return (-1);
		else if (sign == -1 && (-num) < ((-num) * 10 - (*str - 48)))
			return (0);
		num = num * 10 + (*str++ - 48);
	}
	num *= sign;
	return ((long)num);
}

int	ft_atoi(char *str)
{
	long long	num;
	int			sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && num > (num * 10 + (*str - 48)))
			return (-1);
		else if (sign == -1 && (-num) < ((-num) * 10 - (*str - 48)))
			return (0);
		num = num * 10 + (*str++ - 48);
	}
	num *= sign;
	return ((int)num);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	v;

	v = 0;
	while (s1[v] != '\0' && s2[v] != '\0' && s1[v] == s2[v])
		v++;
	if (s1[v] == s2[v])
		return (0);
	else if (s1[v] > s2[v])
		return (1);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	v;

	v = 0;
	while (str[v])
		v++;
	return (v);
}
