/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:28:31 by aancel            #+#    #+#             */
/*   Updated: 2016/11/27 14:37:51 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

char	*extract(char *filename)
{
	char	buf[21];
	char	*dst;
	int		fd;
	int		i;

	dst = "";
	ft_memset(buf, '\0', 21);
	fd = open(filename, O_RDONLY);
	i = 21;
	while (i == 21)
	{
		i = read(fd, buf, 21);
		if (check_buf(buf) == -1)
			return (NULL);
		dst = ft_strjoin(dst, buf);
		ft_memset(buf, '\0', 21);
		if (i != 21 && i != 20)
			return (NULL);
	}
	return (dst);
}

char	**place_tab(char *str, char **dest, char a)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	z = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = (str[z + j] == '#' ? a : str[z + j]);
			j++;
		}
		dest[i][j] = '\0';
		z += j + 1;
		i++;
	}
	dest[i][0] = '\0';
	return (dest);
}
