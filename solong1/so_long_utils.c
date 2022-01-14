#include "lib.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	check_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	collnumberr(t_data *data)
{
	int	x;
	int	y;
	int	k;

	k = 0;
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C')
				k++;
			y++;
		}
		x++;
	}
	return (k);
}

void	ft_free(char **str)
{
	int	i;
	
	i = 0;
	if(str)
	{
		while (str[i])
			free(str[i++]);
		free (str);
	}
}

void	map_error(t_data *data)
{
	free (data->map_d);
	ft_free(data->map);
	write (1, "Map error\n", 11);
	exit(0);
}

void	arg_error(t_data *data)
{
	free (data->map_d);
	ft_free(data->map);
	write (1, "Arg error\n", 11);
	exit(0);
}