/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:23:31 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/22 16:57:56 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_reverse_rotate(t_h_stack *s)
{
	t_stack	*tmp;

	if (s->size < 2)
		return (0);
	tmp = s->stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = s->stack;
	s->stack = tmp->next;
	tmp->next = NULL;
	return (1);
}

void	rra(t_h_stack *a)
{
	if (ft_reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_h_stack *b)
{
	if (ft_reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_h_stack *a, t_h_stack *b)
{
	int	sa;
	int	sb;

	sa = ft_reverse_rotate(a);
	sb = ft_reverse_rotate(b);
	if (sa && sb)
		write(1, "rrr\n", 4);
	else if (sa)
		write(1, "rra\n", 4);
	else if (sb)
		write(1, "rrb\n", 4);
}
