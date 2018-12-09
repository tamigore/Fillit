/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:20:57 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/09 20:23:26 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_fill
{
	char			*content;
	char			index;
	struct s_fill	*next;
	struct s_fill	*prev;
}					t_fill;

char		*ft_safejoin(char *s1, char *s2);
char		*ft_valid_file(int fd);
char		*ft_swapchar(char *buf);
t_fill		*ft_listnew(char index, char *content);
void		ft_listrev(t_fill **begin);
void		ft_listadd(t_fill **begin, t_fill *new);
size_t		ft_listlen(t_fill *list);
void		ft_listiter(t_fill **begin, char *(*f)(char *s));
char		*ft_cutstr(char *p, int i);

#endif
