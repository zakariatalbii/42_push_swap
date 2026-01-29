/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:26:30 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 14:03:35 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_get_max(t_stack *s)
{
	int	max;

	max = s->value;
	s = s->next;
	while (s)
	{
		if (max < s->value)
			max = s->value;
		s = s->next;
	}
	return (max);
}

int	ft_get_min(t_stack *s)
{
	int	min;

	min = s->value;
	s = s->next;
	while (s)
	{
		if (min > s->value)
			min = s->value;
		s = s->next;
	}
	return (min);
}

int	ft_get_end(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->value);
}
