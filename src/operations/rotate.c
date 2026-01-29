/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:53:54 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/28 23:02:50 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_h_stack *s)
{
	t_stack	*tmp;

	if (s->size < 2)
		return (0);
	tmp = s->stack->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = s->stack;
	s->stack = tmp->next->next;
	tmp->next->next = NULL;
	return (1);
}

void	ra(t_h_stack *a)
{
	if (ft_rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_h_stack *b)
{
	if (ft_rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_h_stack *a, t_h_stack *b)
{
	int	sa;
	int	sb;

	sa = ft_rotate(a);
	sb = ft_rotate(b);
	if (sa && sb)
		write(1, "rr\n", 3);
	else if (sa)
		write(1, "ra\n", 3);
	else if (sb)
		write(1, "rb\n", 3);
}
