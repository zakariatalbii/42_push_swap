/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:02:24 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:17:14 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long long	num;
	int			sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '+') - (*str == '-');
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
