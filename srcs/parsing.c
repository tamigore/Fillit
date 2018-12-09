/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:18:44 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/09 20:22:14 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fillit.h"

static int	ft_find_t1(char *p, int i)
{
	if (p[i + 5] == '#' && p[i + 6] == '#')
		return (1);
	else if (p[i + 5] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 11] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 3] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 6] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 5] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 7] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 7] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 5] == '#')
		return (1);
	else
		return (0);
}

static int	ft_find_t5(char *p, int i)
{
	if (p[i + 10] == '#' && p[i + 15] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 11] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 7] == '#')
		return (1);
	else if (p[i + 3] == '#' && p[i + 4] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 9] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 6] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 9] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 10] == '#' && p[i + 11] == '#')
		return (1);
	else
		return (0);
}

static int	ft_valid_tetra(char *p, int i)
{
	while (p[i])
	{
		while (p[i] != '#')
		{
			if (p[i] == '\0')
				return (0);
			i++;
		}
		if (p[i + 1] == '#' && ft_find_t1(p, i))
			return (1);
		else if (p[i + 5] == '#' && ft_find_t5(p, i))
			return (1);
		else
			return (0);
		while (p[i])
		{
			if (p[i] == '\n' && p[i + 1] == ('\n' || '\0'))
				break ;
			if (p[i] == '\0')
				return (0);
			i++;
		}
	}
	return (0);
}

static int	ft_valid_block(char *p, int line, int count)
{
	int i;

	i = 0;
	while (p[i])
	{
		if (p[i] != '.' && p[i] != '\n' && p[i] != '#' && p[i] != '\0')
			return (0);
		if (p[i] == '\n')
			line++;
		if (line == 5 && p[i - 1] == '\n')
		{
			count = 0;
			line = 0;
		}
		else if (line == 5 && p[i - 1] != '\n')
			return (0);
		if (p[i] == '#')
			count++;
		if (line == 4 && count != 4)
			return (0);
		i++;
	}
	return (1);
}

char		*ft_valid_file(int fd)
{
	char	*p;
	char	buf[22];
	int		r;

	if (!(p = ft_strnew(1)) || fd < 0 || read(fd, buf, 0) == -1)
		return (NULL);
	while ((r = read(fd, buf, 21)) > 0)
	{
		buf[r] = '\0';
		if (!(p = ft_safejoin(p, buf)) || r < 20 || ft_strlen(p) > 545)
			return (NULL);
	}
	if (!(ft_valid_tetra(p, 0)) || !(ft_valid_block(p, 0, 0)))
		return (NULL);
	return (p);
}
