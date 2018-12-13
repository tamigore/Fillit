/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:59:38 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/13 19:00:48 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	ft_count(size_t n)
{
	size_t	i;

	i = 1;
	if (n == 1)
		return (1);
	while (i < n)
	{
		i++;
		if (i * i == n)
			return (i);
	}
	return (ft_count(n + 1));
}

char	*ft_init(size_t n)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	n = ft_count(n * 4);
	if (!(tab = ft_strnew(n * n + n)))
		return (NULL);
	while (tab[i])
	{
		if (i % (n + ((n + 1) * j)) == 0 && (i > (n + 1)))
		{
			tab[i] = '\n';
			j++;
		}
		else if (i == n)
		{
			tab[i] = '\n';
			j++;
		}
		i++;
	}
	return (tab);
}

int		*ft_check_place(char *str)
{
	int *tab;
	int lin;
	int col;
	int n;
	int	x;

	lin = 1;
	col = 1;
	n = 0;
	x = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 4)))
		return (0);
	while (str[x])
	{
		if (str[x] != '.' && str[x] != '\n')
		{
			tab[n] = lin * col;
			n++;
		}
		if (str[x] == '\n')
		{
			lin *= 10;
			col = 1;
		}
		else
			col++;
		x++;
	}
	return (tab);
}

char	*backtrack(int i, char *p, int *tab)
{
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(tmp = ft_strdup(p)))
		return (0);
	while (tmp[x])
	{
		if (tmp[x] == '.')
		{
		}
	}
	free(tab);
	free(tmp);
}

int		check_backtrack(t_file list)
{
	char	*p;
	int		*tab;

	if (!(tab = (int *)malloc(sizeof(int) * 4)) \
			|| (!(p = ft_init(ft_lstlen(list)))))
		return (0);
	while (list)
	{
		if (!(tab = ft_check_place(list->content)))
			return (0);
		while (!(backtrack(i, p, tab)))
			i++;
		p = backtrack(i, p, tab);
		list = list->next;
	}
	ft_putstr(p);
	free(p);
}
