/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_ft_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:14:45 by zatalbi           #+#    #+#             */
/*   Updated: 2025/04/18 15:56:45 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_isdigits(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

static int	ft_inrange(long nbr)
{
	if (nbr < (long)INT_MIN || nbr > (long)INT_MAX)
		return (0);
	return (1);
}

static int	ft_isonly(int nbr, char **strs)
{
	int	v;

	v = 0;
	while (strs[v])
	{
		if (nbr == ft_atoi(strs[v++]))
			return (0);
	}
	return (1);
}

void	ft_iserror(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

char	**ft_inputs(int *argp, char **argv)
{
	char	**strs;
	int		v;

	strs = ft_split(*argp - 1, argp, argv + 1, '\t');
	argv = ft_split(*argp, argp, strs, ' ');
	ft_clear_inputs(strs);
	if (!*argp)
		exit(1);
	if (!argv)
		ft_iserror();
	v = 0;
	while (argv[v])
	{
		if (!ft_isdigits(argv[v]) || ft_strlen(argv[v]) > 11
			|| !ft_inrange(ft_atol(argv[v]))
			|| !ft_isonly(ft_atoi(argv[v]), &argv[v + 1]))
		{
			ft_clear_inputs(argv);
			ft_iserror();
		}
		v++;
	}
	return (argv);
}
