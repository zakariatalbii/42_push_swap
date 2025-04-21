/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:32:41 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/22 16:34:51 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
