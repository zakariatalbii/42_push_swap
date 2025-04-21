/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_ft_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:23:33 by zatalbi           #+#    #+#             */
/*   Updated: 2025/03/25 21:51:14 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_countwords(char *s, char c)
{
	int	count;
	int	v;

	count = 0;
	v = 0;
	while (s[v] != '\0' && s[v] == c)
		v++;
	while (s[v] != '\0')
	{
		if ((s[v] == c && s[v - 1] != c)
			|| (s[v] != c && s[v + 1] == '\0'))
			count++;
		v++;
	}
	return (count);
}

static int	ft_wordlen(char **ps, char c)
{
	int	len;

	len = 0;
	while (**ps != '\0' && **ps == c)
		(*ps)++;
	while (**ps != '\0' && **ps != c)
	{
		len++;
		(*ps)++;
	}
	return (len);
}

static void	ft_wordcpy(char *s, char *ps, char c)
{
	int	v;

	while (*ps != '\0' && *ps == c)
		ps++;
	v = 0;
	while (*ps != '\0' && *ps != c)
	{
		s[v++] = *ps;
		ps++;
	}
	s[v] = '\0';
}

static int	ft_wordall(int count, char **strs, char **argv, char c)
{
	char	*s1;
	char	*s2;
	int		cnt;
	int		len;
	int		v;

	v = 0;
	while (v < count)
	{
		s1 = *argv;
		cnt = ft_countwords(*argv++, c);
		while (cnt--)
		{
			s2 = s1;
			len = ft_wordlen(&s1, c);
			strs[v] = (char *)malloc(len + 1);
			if (!strs[v])
				return (v);
			ft_wordcpy(strs[v++], s2, c);
		}
	}
	strs[v] = NULL;
	return (v);
}

char	**ft_split(int argc, int *argp, char **argv, char c)
{
	char	**strs;
	int		cnt;
	int		v;

	if (!argv)
		return (NULL);
	*argp = 0;
	v = 0;
	while (v < argc)
		*argp += ft_countwords(argv[v++], c);
	if (!*argp)
		return (NULL);
	strs = (char **)malloc((*argp + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	cnt = ft_wordall(*argp, strs, argv, c);
	if (cnt < *argp)
	{
		v = 0;
		while (v < cnt)
			free(strs[v++]);
		free(strs);
		return (NULL);
	}
	return (strs);
}
