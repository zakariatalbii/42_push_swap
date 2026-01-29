/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:30:16 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:06:09 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_nout(t_stack *s, char c)
{
	t_stack	*o;

	o = s;
	s = s->next;
	while (s)
	{
		if (s->c_mvs < o->c_mvs
			|| (c == 'a' && s->c_mvs == o->c_mvs && s->value < o->value)
			|| (c == 'b' && s->c_mvs == o->c_mvs && s->value > o->value))
			o = s;
		s = s->next;
	}
	return (o);
}

void	ft_rotate_its(t_h_stack *s, t_h_stack *t, char c)
{
	t_stack	*tmp;

	tmp = ft_nout(s->stack, c);
	while (tmp->d_mvs == 1 && s->stack != tmp && t->stack != tmp->target)
	{
		if (c == 'a')
			rr(s, t);
		else
			rr(t, s);
	}
	while (tmp->d_mvs == -1 && s->stack != tmp && t->stack != tmp->target)
	{
		if (c == 'a')
			rrr(s, t);
		else
			rrr(t, s);
	}
	ft_rotate_it(s, tmp->value, c);
	ft_rotate_it(t, tmp->target->value, 'a' + 'b' - c);
}

void	ft_rotate_it(t_h_stack *s, int t, char c)
{
	t_stack	*tmp;
	int		v;

	v = 0;
	tmp = s->stack;
	while (tmp && t != tmp->value && ++v)
		tmp = tmp->next;
	if (!tmp)
		return ;
	if (v <= s->size / 2)
	{
		while (c == 'a' && v--)
			ra(s);
		while (c == 'b' && v--)
			rb(s);
	}
	else
	{
		while (c == 'a' && s->size - v++)
			rra(s);
		while (c == 'b' && s->size - v++)
			rrb(s);
	}
}
