/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:06 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/07 14:30:55 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_fill	*list;
	char	*p;
	int		fd;
	size_t	i;

	if (ac != 2 || (fd = open(av[1], O_RDWR)) == -1)
	{
		ft_putstr("usage : ./fillit valid_file\n");
		return (0);
	}
	if (!(list = ft_valid_file(fd)))
	{
		ft_putstr("error\n");
		return (0);
	}
	i = ft_count(ft_listlen(list) * 4);
	p = ft_init(i);
	while ((ft_place(p, list, i, 0)) == 0)
	{
		i++;
		free(p);
		p = ft_init(i);
	}
	ft_putstr(p);
	free(p);
	ft_freelst(&list);
	return (0);
}
