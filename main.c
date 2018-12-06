/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:06 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/06 21:28:17 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int	ft_valid_tetra(char *p)
{
	int i;

	i = 0;
	while(p[i])
	{	
		if(p[i] == '#' && p[i + 1] != '#' && p[i + 5] != '#')
		{
			if(i >= 5)
			{
				if(p[i - 1] != '#' && p[i - 5] != '#')
					return (0);
			}
			else if(i >= 1 && i < 5)
			{
				if(p[i - 1] != '#')
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_valid_block(char *p)
{
	int line;
	int count;
	int i;

	i = 0;
	line = 0;
	count = 0;
	while (p[i])
	{
		if(p[i] != '.' && p[i] != '\n' && p[i] != '#' && p[i] != '\0')
		{
			ft_putnbr(i);
			ft_putstr(" bug\n");
			return (0);
		}
		if(p[i] == '\n')
			line++;
		if(line == 5)
		{
			count = 0;
			line = 0;
		}
		if(p[i] == '#')
			count++;
		if(line == 4 && count != 4)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_valid_file(int fd)
{
	char	*p;
	char	buf[22];
	int		i;
	int		diz;
	int		r;

	i = 0;
	diz = 0;
	if(!(p = ft_strnew(1)))
		return (0);
	while((r = read(fd, buf, 21)) > 0)
		if(!(p = ft_safejoin(p, buf)) || r < 20 || ft_strlen(p) > 545)
			return (0);	
	if (!(ft_valid_tetra(p)) || !(ft_valid_block(p)))
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	int fd;

	if(ac != 2 || (fd = open(av[1], O_RDWR)) == -1)
	{
		ft_putstr("usage : ./fillit valid_file\n");
		return (0);
	}
	if(!ft_valid_file(fd))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}
