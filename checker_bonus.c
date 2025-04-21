/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:33:21 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 22:22:40 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_check_op(t_h_stack *a, t_h_stack *b, char *str)
{
	if ((!ft_strcmp(str, "sa\n") && sa(a))
		|| (!ft_strcmp(str, "sb\n") && sb(b))
		|| (!ft_strcmp(str, "ss\n") && ss(a, b))
		|| (!ft_strcmp(str, "pa\n") && pa(a, b))
		|| (!ft_strcmp(str, "pb\n") && pb(b, a))
		|| (!ft_strcmp(str, "ra\n") && ra(a))
		|| (!ft_strcmp(str, "rb\n") && rb(b))
		|| (!ft_strcmp(str, "rr\n") && rr(a, b))
		|| (!ft_strcmp(str, "rra\n") && rra(a))
		|| (!ft_strcmp(str, "rrb\n") && rrb(b))
		|| (!ft_strcmp(str, "rrr\n") && rrr(a, b)))
		return (1);
	return (0);
}

static void	ft_checker(t_h_stack *a, t_h_stack *b)
{
	char	*str;

	str = get_next_line(0);
	while (str && ft_check_op(a, b, str))
	{
		free(str);
		str = get_next_line(0);
	}
	if (str)
	{
		free(str);
		ft_clear_stack(&a->stack);
		ft_clear_stack(&b->stack);
		ft_iserror();
	}
	else
	{
		if (!b->size && ft_circo(a) && ft_get_min(a->stack) == a->stack->value)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_h_stack	a;
	t_h_stack	b;

	argv = ft_inputs(&argc, argv);
	a = (t_h_stack){argc, ft_stack(argc, argv)};
	b = (t_h_stack){0, NULL};
	ft_checker(&a, &b);
	ft_clear_stack(&a.stack);
	ft_clear_stack(&b.stack);
	exit(0);
}
