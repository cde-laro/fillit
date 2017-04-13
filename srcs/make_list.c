/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:25:15 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/27 15:29:21 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

int			ft_sqrt(int nb)
{
	int		dest;

	dest = 0;
	while (dest * dest < nb)
		dest++;
	return (dest);
}

t_tetris	*n_p(char **content)
{
	t_tetris	*piece;

	piece = malloc(sizeof(t_tetris));
	piece->piece = content;
	piece->next = NULL;
	return (piece);
}

t_tetris	*make_list(char *s)
{
	int			i;
	t_tetris	*p;
	char		a;
	t_tetris	*f;

	if (s[22])
	{
		f = n_p(place_tab(ft_strsub(s, 0, 21), ft_create_tab(5, 5), 'A'));
		p = f;
		i = 21;
		a = 'B';
		while (s[i])
		{
			p->next = n_p(place_tab(ft_strsub(s, i, (s[i + 21] ? 21 : 20)),
						ft_create_tab(5, 5), a));
			if (f->next == NULL)
				f->next = p;
			i += 21;
			a++;
			p = p->next;
		}
	}
	else
		f = n_p(place_tab(ft_strsub(s, 0, 20), ft_create_tab(5, 5), 'A'));
	return (f);
}
