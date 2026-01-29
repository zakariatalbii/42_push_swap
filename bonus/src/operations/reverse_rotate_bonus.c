/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:23:31 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 13:26:57 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_reverse_rotate(t_h_stack *s)
{
	t_stack	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = s->stack;
	s->stack = tmp->next;
	tmp->next = NULL;
}

int	rra(t_h_stack *a)
{
	ft_reverse_rotate(a);
	return (1);
}

int	rrb(t_h_stack *b)
{
	ft_reverse_rotate(b);
	return (1);
}

int	rrr(t_h_stack *a, t_h_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	return (1);
}
