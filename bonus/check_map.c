#include "lib.h"

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
			if (map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_map2(char **map)
{
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;

	i = 0;
	j = 0;
	e = 0;
	p = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (e == 0)
		return (0);
	if (p != 1)
		return (0);
	if (c == 0)
		return (0);
	return (check_map3(map));
}

int check_map(char **map_c, char *map)
{
	int		i;
	int		j;

	while (map_c[i])
	{
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
		if (len(map_c[0]) != len(map_c[i]))
			return (0);
		j = 0;
		i++;
	}
	if (check_len(map_c) - 1 != check_nextline(map))
		return (0);
	return (check_map2(map_c));
}
