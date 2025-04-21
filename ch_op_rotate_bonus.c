/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_op_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:53:54 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 22:10:34 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_rotate(t_h_stack *s)
{
	t_stack	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->stack->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = s->stack;
	s->stack = tmp->next->next;
	tmp->next->next = NULL;
}

int	ra(t_h_stack *a)
{
	ft_rotate(a);
	return (1);
}

int	rb(t_h_stack *b)
{
	ft_rotate(b);
	return (1);
}

int	rr(t_h_stack *a, t_h_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	return (1);
}
