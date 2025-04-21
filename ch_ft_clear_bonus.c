/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_ft_clear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:32:41 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 21:47:38 by zatalbi          ###   ########.fr       */
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

void	ft_clear_inputs(char **argv)
{
	int	v;

	if (!argv)
		return ;
	v = 0;
	while (argv[v])
		free(argv[v++]);
	free(argv);
	argv = NULL;
}
