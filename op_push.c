/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:50:09 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/22 16:50:39 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_h_stack *dst, t_h_stack *src)
{
	t_stack	*tmp;

	if (!src->size)
		return (0);
	tmp = src->stack;
	src->stack = tmp->next;
	tmp->next = dst->stack;
	dst->stack = tmp;
	src->size--;
	dst->size++;
	return (1);
}

void	pa(t_h_stack *a, t_h_stack *b)
{
	if (ft_push(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_h_stack *b, t_h_stack *a)
{
	if (ft_push(b, a))
		write(1, "pb\n", 3);
}
