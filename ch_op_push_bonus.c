/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_op_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:50:09 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 22:09:29 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_push(t_h_stack *dst, t_h_stack *src)
{
	t_stack	*tmp;

	if (!src->size)
		return ;
	tmp = src->stack;
	src->stack = tmp->next;
	tmp->next = dst->stack;
	dst->stack = tmp;
	src->size--;
	dst->size++;
}

int	pa(t_h_stack *a, t_h_stack *b)
{
	ft_push(a, b);
	return (1);
}

int	pb(t_h_stack *b, t_h_stack *a)
{
	ft_push(b, a);
	return (1);
}
