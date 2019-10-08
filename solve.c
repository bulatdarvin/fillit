/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssilvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:06:10 by ssilvana          #+#    #+#             */
/*   Updated: 2019/09/30 18:26:54 by qsharoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**solve(t_tet *elem)
{
	char	**res;
	char	**map;
	int		size;

	size = ft_sqrt(4 * tetris_size(elem));
	if (!(map = create_map(size)))
		return (NULL);
	while (!(res = algoritm(map, size, elem)))
	{
		size++;
		ft_memdeltab(map);
		if (!(map = create_map(size)))
			return (NULL);
	}
	return (res);
}

char	**algoritm(char **map, int size, t_tet *elem)
{
	t_point	p;
	char	**tetris;

	if (elem == NULL)
		return (map);
	tetris = NULL;
	p.y = 0;
	while (p.y < size)
	{
		p.x = 0;
		while (p.x < size)
		{
			if (check_map(map, elem, size, p))
			{
				if ((tetris = algoritm(insert_tetris(map, elem, p),
						size, elem->next)) != NULL)
					return (tetris);
				remove_tetris(map, elem, p);
			}
			p.x++;
		}
		p.y++;
	}
	return (NULL);
}

int		compare(int a[8], int b[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}
