/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:09:35 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/04 19:08:01 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 21

typedef	struct	s_fill
{
	char			*content;
	char			index;
	size_t			x;
	struct s_fill	*next;
	struct s_fill	*prev;
}				t_fill;

int				main(int ac, char **av);
char			*ft_swap(char *buf, char index);
char			*ft_safejoin(char *s1, char *s2);
t_fill			*ft_valid_file(int fd);
t_fill			*ft_listnew(char index, char *content);
void			ft_listrev(t_fill **begin);
void			ft_listadd(t_fill **begin, t_fill *new, char c);
size_t			ft_listlen(t_fill *list);
void			ft_listiter(t_fill **begin, char *(*f)(char *s));
char			*ft_init(size_t n);
size_t			ft_count(size_t n);
int				ft_place(char *tab, t_fill *new, size_t n, size_t i);
char			*ft_cutstr(char *p, int i);
size_t			ft_deletetetra(char c, char *tab);
size_t			ft_backtracking(t_fill *list, char *tab, size_t n);
int				ft_checkiterative(char *tab, t_fill *list, size_t i, size_t n);
void			ft_fill(char *tab, t_fill *new, size_t j, size_t n);
int				ft_check(char *tab, t_fill *new, size_t j, size_t n);
int				ft_countz(char *buf, size_t y);
int				ft_checkoptileft(char *tab, t_fill *new, size_t n);
void			ft_placeleft(char *tab, char c);
void			ft_checkoptiz(char *tab, t_fill *new, size_t j, size_t n);

#endif
