/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:37:00 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:12:55 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_h_stack *a, t_h_stack *b)
{
	while (!ft_circo(a) && a->size > 3)
	{
		pb(b, a);
		if (a->size == 3)
			break ;
		ft_indexer(a);
		ft_indexer(b);
		ft_target(a->stack, b->stack, 'a');
		ft_mvs(a->stack, a->size, b->size);
		ft_rotate_its(a, b, 'a');
	}
	if (a->size == 3)
		ft_order_three(a);
	while (b->size)
	{
		ft_indexer(a);
		ft_indexer(b);
		ft_target(b->stack, a->stack, 'b');
		ft_mvs(b->stack, b->size, a->size);
		ft_rotate_its(b, a, 'b');
		pa(a, b);
	}
	ft_rotate_it(a, ft_get_min(a->stack), 'a');
}
