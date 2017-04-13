/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:14:03 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/28 18:51:13 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_links(char **c, int i, int j)
{
	int		l;

	l = 0;
	if (i != 0)
		(c[i - 1][j] != '.' ? l++ : 0);
	if (i != 3)
		(c[i + 1][j] != '.' ? l++ : 0);
	if (j != 0)
		(c[i][j - 1] != '.' ? l++ : 0);
	if (j != 3)
		(c[i][j + 1] != '.' ? l++ : 0);
	return (l);
}

int		check_piece(char **piece)
{
	int		i;
	int		j;
	int		tl;
	int		l;

	i = 0;
	l = 0;
	tl = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] != '.')
			{
				l = 0;
				if ((l = check_links(piece, i, j)) == 0)
					return (-1);
				tl += l;
			}
			j++;
		}
		i++;
	}
	return (tl == 6 || tl == 8 ? 0 : -1);
}

int		check_char(char *str)
{
	int		i;
	int		n;
	int		c;
	int		p;

	n = 0;
	c = 0;
	p = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		else if (str[i] == '#')
			c++;
		else if (str[i] == '.')
			p++;
		else
			return (0);
		i++;
	}
	return (c == 4 && p == 12 ? 1 : 0);
}

int		check_input(t_tetris *piece)
{
	while (piece)
	{
		if (check_piece(piece->piece) == -1)
			return (-1);
		piece = piece->next;
	}
	return (0);
}

int		check_buf(char *str)
{
	int i;
	int n;

	n = 1;
	if (check_char(str) == 0)
		return (-1);
	i = 4;
	while (i <= 20)
	{
		if (str[i] != '\n')
			return (-1);
		n++;
		i += 5;
	}
	if (str[20] != '\n' && str[20] != '\0')
		return (-1);
	return (0);
}
