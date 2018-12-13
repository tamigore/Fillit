/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:06 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/13 18:23:32 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_fill	*list;
	char	c;
	char	*p;
	int		*tab;
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
		ft_listadd(&list, ft_listnew(c, ft_cutstr(p, i)), c);
		c++;
		if (p[i + 20] == '\0')
			break ; 
		i += 21;
	}
	free(p);
	while (list)
	{
		tab = ft_check_place(list->content);
		list = list->next;
		printf("%d  %d  %d  %d\n", tab[0], tab[1], tab[2], tab[3]);
	}
	free(tab);
	return (0);
}
