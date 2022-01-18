/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_is_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:50:25 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 19:50:28 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

typedef struct s_var
{
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;
}		t_var;

int	check_nextline(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	check_map3(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0'
			&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map2(char **map)
{
	t_var	k;

	k.i = 0;
	k.j = 0;
	k.e = 0;
	k.p = 0;
	k.c = 0;
	while (map[k.i])
	{
		k.j = 0;
		while (map[k.i][k.j])
		{
			if (map[k.i][k.j] == 'E')
				k.e++;
			if (map[k.i][k.j] == 'P')
				k.p++;
			if (map[k.i][k.j] == 'C')
				k.c++;
			k.j++;
		}
		k.i++;
	}
	if (k.e == 0 || k.p != 1 || k.c == 0)
		return (0);
	return (check_map3(map));
}

int	check_map(char **map_c, char *map)
{
	int	i;
	int	j;

	i = 0;
	while (map_c[i])
	{
		j = 0;
		while (map_c[i][j])
		{
			if (i + 1 == check_len(map_c) && map_c[i][j] != '1')
				return (0);
			if (i == 0 && map_c[i][j] != '1')
				return (0);
			if (j == 0 && map_c[i][j] != '1')
				return (0);
			if (!map_c[i][j + 1] && map_c[i][j] != '1')
				return (0);
			j++;
		}
		if (len(map_c[0]) != len(map_c[i])
			|| check_len(map_c) - 1 != check_nextline(map))
			return (0);
		i++;
	}
	return (check_map2(map_c));
}
