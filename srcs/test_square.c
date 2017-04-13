/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:25:47 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/27 14:39:55 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

void	print_square(char **square)
{
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(square[0]);
	while (i < n)
	{
		ft_putendl(square[i]);
		i++;
	}
}

char	**test_square(t_tetris *piece, size_t size)
{
	size_t		i;
	size_t		j;
	char		**square;

	i = 0;
	if (!(square = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		j = -1;
		if (!(square[i] = ft_memalloc(size + 1)))
			return (NULL);
		while (++j < size)
			square[i][j] = '.';
		square[i][j] = '\0';
		i++;
	}
	square[i] = malloc(1);
	square[i][0] = '\0';
	if ((square = test_piece(piece, 0, 0, square)) == NULL)
		return (test_square(piece, size + 1));
	print_square(square);
	return (square);
}
