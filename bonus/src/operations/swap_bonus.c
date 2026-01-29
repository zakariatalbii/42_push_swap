/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:21:41 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 13:27:34 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_swap(t_h_stack *s)
{
	t_stack	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->stack;
	s->stack = tmp->next;
	tmp->next = s->stack->next;
	s->stack->next = tmp;
}

int	sa(t_h_stack *a)
{
	ft_swap(a);
	return (1);
}

int	sb(t_h_stack *b)
{
	ft_swap(b);
	return (1);
}

int	ss(t_h_stack *a, t_h_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	return (1);
}
