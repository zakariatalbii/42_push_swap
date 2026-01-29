/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 06:38:50 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 14:06:45 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	v;

	v = 0;
	while (s1[v] && s2[v] && s1[v] == s2[v])
		v++;
	if (s1[v] == s2[v])
		return (0);
	else if (s1[v] > s2[v])
		return (1);
	return (-1);
}
