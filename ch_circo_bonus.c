/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_circo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:26:30 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 22:00:19 by zatalbi          ###   ########.fr       */
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

int	ft_circo(t_h_stack *s)
{
	t_stack	*tmp;
	int		max;
	int		min;
	int		end;

	if (s->size < 3)
		return (1);
	tmp = s->stack;
	max = ft_get_max(tmp);
	min = ft_get_min(tmp);
	end = ft_get_end(tmp);
	if (end > tmp->value && end != max)
		return (0);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value && (max != tmp->value
				|| min != tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
