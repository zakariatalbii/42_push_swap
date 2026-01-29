/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:03:52 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:08:36 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_target_a(t_stack *b, int ac)
{
	int	max;
	int	min;
	int	target;

	max = ft_get_max(b);
	min = ft_get_min(b);
	if (ac > max || ac < min)
		return (max);
	target = b->value;
	b = b->next;
	while (b)
	{
		if (ac > b->value && ((target > ac && target > b->value)
				|| (target < ac && target < b->value)))
			target = b->value;
		b = b->next;
	}
	return (target);
}

static int	ft_target_b(t_stack *a, int bc)
{
	int	max;
	int	min;
	int	target;

	max = ft_get_max(a);
	min = ft_get_min(a);
	if (bc > max || bc < min)
		return (min);
	target = a->value;
	a = a->next;
	while (a)
	{
		if (bc < a->value && ((target > bc && target > a->value)
				|| (target < bc && target < a->value)))
			target = a->value;
		a = a->next;
	}
	return (target);
}

void	ft_target(t_stack *s, t_stack *t, char c)
{
	t_stack	*tmp;
	int		target;

	while (s)
	{
		if (c == 'a')
			target = ft_target_a(t, s->value);
		else
			target = ft_target_b(t, s->value);
		tmp = t;
		while (tmp)
		{
			if (target == tmp->value)
				break ;
			tmp = tmp->next;
		}
		s->target = tmp;
		s = s->next;
	}
}
