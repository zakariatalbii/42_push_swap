/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_ft_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:28:02 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 21:52:12 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_stack	*ft_make_stack(int argc, char **argv)
{
	t_stack	*s;
	t_stack	*tmp;
	int		v;

	v = 0;
	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	tmp = s;
	tmp->value = ft_atoi(argv[v++]);
	while (v < argc)
	{
		tmp->next = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		tmp->value = ft_atoi(argv[v++]);
	}
	tmp->next = NULL;
	if (v < argc)
		ft_clear_stack(&s);
	return (s);
}

t_stack	*ft_stack(int argc, char **argv)
{
	t_stack	*s;

	s = ft_make_stack(argc, argv);
	ft_clear_inputs(argv);
	if (!s)
		ft_iserror();
	return (s);
}
