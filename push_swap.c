/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:37:02 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 22:49:31 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_h_stack	a;
	t_h_stack	b;

	argv = ft_inputs(&argc, argv);
	a = (t_h_stack){argc, ft_stack(argc, argv)};
	b = (t_h_stack){0, NULL};
	ft_sort(&a, &b);
	ft_clear_stack(&a.stack);
	exit(0);
}
