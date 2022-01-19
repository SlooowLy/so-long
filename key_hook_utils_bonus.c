/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:42:52 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 19:42:55 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

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
	if (i == D)
		m = data->map[--x][--y + 1];
	if (i == A)
		m = data->map[--x][--y - 1];
	if (i == S)
		m = data->map[--x + 1][--y];
	if (i == W)
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

int	check_safety1(t_data *data, int i)
{
	char	m;

	m = get_x_y(data, i, 0);
	if (m == 'E')
	{
		if (data->mapinfo.collnumber == data->mapinfo.collgot)
		{
			mlx_clear_window(data->ml, data->wi);
			data->message = 2;
			ft_exit (data);
		}
		return (0);
	}
	return (1);
}

int	check_enemy(t_data *data, int i)
{
	char	m;

	m = get_x_y(data, i, 0);
	if (m == 'X')
	{
		data->message = 1;
		ft_exit(data);
		return (0);
	}
	return (1);
}
