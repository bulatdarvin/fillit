/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssilvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:07:28 by ssilvana          #+#    #+#             */
/*   Updated: 2019/09/30 18:25:52 by qsharoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**insert_tetris(char **map, t_tet *elem, t_point p)
{
	int i;

	i = 0;
	while (i < 8)
	{
		map[p.y + elem->tet_id[i + 1]][p.x + elem->tet_id[i]] = elem->c;
		i = i + 2;
	}
	return (map);
}

int		check_map(char **map, t_tet *elem, int size, t_point p)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (p.x + elem->tet_id[i] >= size || p.y + elem->tet_id[i + 1] >= size
			|| map[p.y + elem->tet_id[i + 1]][p.x + elem->tet_id[i]] != '.')
			return (0);
		i = i + 2;
	}
	return (1);
}

void	remove_tetris(char **map, t_tet *elem, t_point p)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		map[p.y + elem->tet_id[i + 1]][p.x + elem->tet_id[i]] = '.';
		i = i + 2;
	}
}

void	set_tetris(t_tet **elem, char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && i < 20)
	{
		if (s[i] == '#')
		{
			(*elem)->tet_id[j] = i % 5;
			j++;
			(*elem)->tet_id[j] = i / 5;
			j++;
		}
		i++;
	}
	shift(*elem);
}
