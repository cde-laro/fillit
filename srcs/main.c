/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:03:14 by aancel            #+#    #+#             */
/*   Updated: 2016/12/02 14:10:17 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	char		*str;
	t_tetris	*tetris;
	int			nb_case;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	if (!(str = extract(argv[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	nb_case = (ft_strlen(str) + 1) / 21 * 4;
	tetris = make_list(str);
	if (check_input(tetris) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	test_square(tetris, ft_sqrt(nb_case));
	return (0);
}
