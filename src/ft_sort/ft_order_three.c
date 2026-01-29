/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:26:30 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:03:29 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_three(t_h_stack *s)
{
	int	end;

	end = ft_get_end(s->stack);
	if ((end > s->stack->value && end < s->stack->next->value)
		|| (((end > s->stack->value && end > s->stack->next->value)
				|| (end < s->stack->value && end < s->stack->next->value))
			&& (s->stack->value > s->stack->next->value)))
		sa(s);
}
