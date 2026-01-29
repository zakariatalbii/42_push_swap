/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:32:41 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/28 23:38:44 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
