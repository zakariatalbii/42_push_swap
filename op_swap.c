/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:21:41 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/22 17:25:55 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_h_stack *s)
{
	t_stack	*tmp;

	if (s->size < 2)
		return (0);
	tmp = s->stack;
	s->stack = tmp->next;
	tmp->next = s->stack->next;
	s->stack->next = tmp;
	return (1);
}

void	sa(t_h_stack *a)
{
	if (ft_swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_h_stack *b)
{
	if (ft_swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_h_stack *a, t_h_stack *b)
{
	int	sa;
	int	sb;

	sa = ft_swap(a);
	sb = ft_swap(b);
	if (sa && sb)
		write(1, "ss\n", 3);
	else if (sa)
		write(1, "sa\n", 3);
	else if (sb)
		write(1, "sb\n", 3);
}
