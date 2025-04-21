/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sinfo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:20:11 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/24 18:19:16 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_the_min(int uu, int dd, int ud, int du)
{
	int	min;

	min = uu;
	if (dd < min)
		min = dd;
	if (ud < min)
		min = ud;
	if (du < min)
		min = du;
	return (min);
}

void	ft_mvs(t_stack *s, int ssize, int tsize)
{
	int	uu;
	int	dd;

	while (s)
	{
		if (s->index >= s->target->index)
			uu = s->index;
		else
			uu = s->target->index;
		if (ssize - s->index >= tsize - s->target->index)
			dd = ssize - s->index;
		else
			dd = tsize - s->target->index;
		s->c_mvs = ft_the_min(uu, dd, tsize + s->index - s->target->index,
				ssize - s->index + s->target->index);
		if (uu == s->c_mvs)
			s->d_mvs = 1;
		else if (dd == s->c_mvs)
			s->d_mvs = -1;
		else
			s->d_mvs = 0;
		s = s->next;
	}
}
