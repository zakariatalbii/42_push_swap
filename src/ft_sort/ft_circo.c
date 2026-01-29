/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:26:30 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:03:52 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_circo(t_h_stack *s)
{
	t_stack	*tmp;
	int		max;
	int		min;
	int		end;

	if (s->size < 3)
		return (1);
	tmp = s->stack;
	max = ft_get_max(tmp);
	min = ft_get_min(tmp);
	end = ft_get_end(tmp);
	if (end > tmp->value && end != max)
		return (0);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value && (max != tmp->value
				|| min != tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
