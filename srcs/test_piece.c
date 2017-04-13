/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:38:50 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/27 15:14:28 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

char	**ft_squaredup(char **src)
{
	int		i;
	int		j;
	int		len;
	char	**dest;

	i = 0;
	j = 0;
	len = ft_strlen(src[0]);
	if (!(dest = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (src[i][0])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = ft_strdup("\0");
	return (dest);
}

int		is_ok(t_tetris *piece, int i, int j, char **d)
{
	int		a;
	int		b;
	int		s;

	a = 0;
	s = ft_strlen(d[0]);
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (piece->piece[a][b] != '.')
			{
				if ((a - 3 + i < 0 || b - 3 + j < 0) || (a - 3 + i > s
							|| b - 3 + j > s))
					return (0);
				if (d[a - 3 + i][b - 3 + j] != '.')
					return (0);
			}
			b++;
		}
		a++;
	}
	return (1);
}

char	**print_on_square(t_tetris *piece, int i, int j, char **sq)
{
	int		a;
	int		b;
	int		x;

	x = 0;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (piece->piece[a][b] != '.')
			{
				if (sq[a - 3 + i][b - 3 + j] != '.')
					return (NULL);
				sq[a - 3 + i][b - 3 + j] = piece->piece[a][b];
			}
			b++;
		}
		a++;
	}
	return (sq);
}

int		next_ok(t_tetris *piece, int *i, int *j, char **s)
{
	while (*i < 5 || s[*i - 3][0])
	{
		while (*j < 5 || s[0][*j - 3] || s[0][*j])
		{
			if (is_ok(piece, *i, *j, s))
				return (1);
			*j = *j + 1;
		}
		*j = 0;
		*i = *i + 1;
	}
	return (0);
}

char	**test_piece(t_tetris *piece, int i, int j, char **sq)
{
	char	**tmp;

	if (next_ok(piece, &i, &j, sq) == 0)
		return (NULL);
	if (!(tmp = print_on_square(piece, i, j, ft_squaredup(sq))))
		return (NULL);
	if (!piece->next)
		return (tmp);
	if ((tmp = test_piece(piece->next, 0, 0, ft_squaredup(tmp))))
		return (tmp);
	if (sq[0][j + 1] || sq[0][j - 2])
	{
		if ((tmp = test_piece(piece, i, j + 1, ft_squaredup(sq))))
			return (tmp);
	}
	else if (i < 5 || sq[i - 2][0])
	{
		if ((tmp = test_piece(piece, i + 1, 0, ft_squaredup(sq))))
			return (tmp);
	}
	return (NULL);
}
