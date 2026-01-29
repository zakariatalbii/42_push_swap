/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:33:21 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 15:04:34 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line_bonus.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_h_stack
{
	int		size;
	t_stack	*stack;
}	t_h_stack;

t_stack	*ft_stack(int argc, char **argv);
void	ft_clear_stack(t_stack **s);

char	**ft_inputs(int *argp, char **argv);
void	ft_clear_inputs(char **argv);

char	**ft_split(int argc, int *argp, char **argv, char c);

int		ft_atoi(char *str);
long	ft_atol(char *str);

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);

void	ft_iserror(void);

int		pa(t_h_stack *a, t_h_stack *b);
int		pb(t_h_stack *b, t_h_stack *a);

int		sa(t_h_stack *a);
int		sb(t_h_stack *b);
int		ss(t_h_stack *a, t_h_stack *b);

int		ra(t_h_stack *a);
int		rb(t_h_stack *b);
int		rr(t_h_stack *a, t_h_stack *b);

int		rra(t_h_stack *a);
int		rrb(t_h_stack *b);
int		rrr(t_h_stack *a, t_h_stack *b);

int		ft_circo(t_h_stack *s);

int		ft_get_max(t_stack *s);
int		ft_get_min(t_stack *s);
int		ft_get_end(t_stack *s);

#endif