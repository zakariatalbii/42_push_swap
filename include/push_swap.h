/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:38:47 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/29 00:31:06 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				value;
	int				c_mvs;
	int				d_mvs;
	struct s_stack	*next;
	struct s_stack	*target;
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

int		ft_strlen(char *str);

void	ft_iserror(void);

void	pa(t_h_stack *a, t_h_stack *b);
void	pb(t_h_stack *b, t_h_stack *a);

void	sa(t_h_stack *a);
void	sb(t_h_stack *b);
void	ss(t_h_stack *a, t_h_stack *b);

void	ra(t_h_stack *a);
void	rb(t_h_stack *b);
void	rr(t_h_stack *a, t_h_stack *b);

void	rra(t_h_stack *a);
void	rrb(t_h_stack *b);
void	rrr(t_h_stack *a, t_h_stack *b);

void	ft_sort(t_h_stack *a, t_h_stack *b);

int		ft_circo(t_h_stack *s);

void	ft_order_three(t_h_stack *s);

void	ft_indexer(t_h_stack *s);
void	ft_target(t_stack *s, t_stack *t, char c);
void	ft_mvs(t_stack *s, int ssize, int tsize);

int		ft_get_max(t_stack *s);
int		ft_get_min(t_stack *s);
int		ft_get_end(t_stack *s);

void	ft_rotate_its(t_h_stack *s, t_h_stack *t, char c);
void	ft_rotate_it(t_h_stack *s, int t, char c);

#endif