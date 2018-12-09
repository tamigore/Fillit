/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:06 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/09 20:28:41 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_fill	*list;
	char	c;
	char	*p;
	int 	fd;
	int 	i;

	if (ac != 2 || (fd = open(av[1], O_RDWR)) == -1)
	{
		ft_putstr("usage : ./fillit valid_file\n");
		return (0);
	}
	if (!(p = ft_valid_file(fd)))
	{
		ft_putstr("error\n");
		return (0);
	}
	c = 'A';
	i = 0;
	while(p[i])
	{
		ft_listadd(&list, ft_listnew(c, ft_cutstr(p, i)));
		c++;
		i += 21;
	}
	i = 0;
	while (list)
	{
		printf("index=%c\n", list->index);
		list = list->next;
		i++;
	}
	printf("i=%d\n", i);
	return (0);
}
