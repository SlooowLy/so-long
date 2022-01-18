/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:15:09 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:15:11 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	get_x_y(t_data *data, int i, char m)
{
	int		x;
	int		y;

	x = 0;
	m = 1;
	while (data->map[x] && m)
	{
		y = 0;
		while (data->map[x][y] && m)
		{
			if (data->map[x][y] == 'P')
				m = 0;
			y++;
		}
		x++;
	}
	if (i == d)
		m = data->map[--x][--y + 1];
	if (i == a)
		m = data->map[--x][--y - 1];
	if (i == s)
		m = data->map[--x + 1][--y];
	if (i == w)
		m = data->map[--x - 1][--y];
	return (m);
}

int	check_safety(t_data *data, int i)
{
	char	m;

	m = get_x_y(data, i, 0);
	if (m == 'C')
	{
		data->mapinfo.collgot++;
		if (data->mapinfo.collgot == data->mapinfo.collnumber)
			data->player_eve = 0;
	}
	if (m == '1')
		return (0);
	return (1);
}

void	destroy_all(t_data *data)
{
	mlx_clear_window(data->ml, data->wi);
	free (data->map_d);
	ft_free(data->map);
	exit(0);
}

int	check_safety1(t_data *data, int i)
{
	char	m;

	m = get_x_y(data, i, 0);
	if (m == 'E')
	{
		if (data->mapinfo.collnumber == data->mapinfo.collgot)
			destroy_all(data);
		return (0);
	}
	return (1);
}
