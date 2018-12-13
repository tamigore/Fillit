/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:03:13 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/11 17:34:36 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strnjoin_free(char *s1, char *s2, int r)
{
	char	*join;
	int		diff;
	char	*tmp;

	tmp = s1;
	diff = ft_strlen(s2) - r;
	if (!s1 || !s2 || !(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) - diff)))
		return (NULL);
	ft_strcat(join, s1);
	ft_strncat(join, s2, r);
	free(tmp);
	return (join);
}

char		*ft_fill(t_fill **begin)
{
	t_fill	*current;
	int		i;
	char	*tab;

	i = 1;
	current = *begin;
	tab = ft_strdup("");
	while (current)
	{
		tab = ft_strnjoin_free(tab, current->content, 21 * i);
		current = current->next;
		i++;
	}
	i = 0;
	return (tab);
}
