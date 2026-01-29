/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_stack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:32:41 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 13:45:41 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_clear_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (*s)
	{
		tmp = *s;
		*s = tmp->next;
		free(tmp);
	}
}
