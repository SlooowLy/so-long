/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:14:50 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:14:51 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	get_position(t_data *data, int *k, int*m)
{
	int	x;
	int	y;
	int	j;

	x = 0;
	j = 1;
	while (data->map[x] && j)
	{
		y = 0;
		while (data->map[x][y] && j)
		{
			if (data->map[x][y] == 'P')
				j = 0;
			y++;
		}
		x++;
	}
	x--;
	y--;
	(*k) = x;
	(*m) = y;
}

void	put_images(t_data *data, int key)
{
	int	x;
	int	y;

	get_position(data, &x, &y);
	if (key == D)
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
	}
	else if (key == A)
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
	}
	else if (key == S)
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
	}
	else if (key == W)
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
	}
	player_animation(key, data);
}

void	key_hook2(int key, t_data *m)
{
	if (key == A && check_safety(m, A) && check_safety1(m, A))
	{
		put_images(m, A);
		ft_printf_d(m->numberofmovements, 1);
		m->numberofmovements++;
	}
	else if (key == S && check_safety(m, S) && check_safety1(m, S))
	{
		put_images(m, S);
		ft_printf_d(m->numberofmovements, 1);
		m->numberofmovements++;
	}
	else if (key == W && check_safety(m, W) && check_safety1(m, W))
	{
		put_images(m, W);
		ft_printf_d(m->numberofmovements, 1);
		m->numberofmovements++;
	}
}

int	key_hook(int key, t_data *m)
{
	if (key == 53)
		destroy_all(m);
	if (key == D && check_safety(m, D) && check_safety1(m, D))
	{
		put_images(m, D);
		ft_printf_d(m->numberofmovements, 1);
		m->numberofmovements++;
	}
	key_hook2(key, m);
	if (m->mapinfo.collgot == m->mapinfo.collnumber)
		m->im.i6 = mlx_xpm_file_to_image(m->ml, R5, &m->wt, &m->hg);
	return (1);
}
