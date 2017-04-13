/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:11:23 by aancel            #+#    #+#             */
/*   Updated: 2016/11/27 15:14:42 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

typedef struct		s_tetris
{
	char			**piece;
	struct s_tetris	*next;
}					t_tetris;

char				*extract(char *filename);
int					check_piece(char **str);
int					check_links(char **c, int i, int j);
int					check_input(t_tetris *piece);
char				**ft_squaredup(char **src);
int					is_ok(t_tetris *piece, int i, int j, char **d);
char				**print_on_square(t_tetris *piece, int i, int j, char **sq);
char				**test_piece(t_tetris *piece, int i, int j, char **sq);
char				**test_square(t_tetris *piece, size_t size);
int					check_char(char *str);
int					check_buf(char *str);
char				**place_tab(char *str, char **dest, char a);
t_tetris			*make_list(char *str);
t_tetris			*new_piece(char **content);
int					ft_sqrt(int nb);
void				print_square(char **square);

#endif
