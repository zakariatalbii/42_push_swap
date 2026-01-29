/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:03:52 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:09:09 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexer(t_h_stack *s)
{
	t_stack	*tmp;
	int		v;

	v = 0;
	tmp = s->stack;
	while (tmp)
	{
		tmp->index = v++;
		tmp = tmp->next;
	}
}
