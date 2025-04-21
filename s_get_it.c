/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_get_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:35:15 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/23 21:20:36 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
