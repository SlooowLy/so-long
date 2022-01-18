/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:43:00 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 19:43:02 by aaitoual         ###   ########.fr       */
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
	if (key == d)
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
	}
	else if (key == a)
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
	}
	else if (key == s)
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
	}
	else if (key == w)
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
	}
	player_animation(key, data);
}

void	key_hook2(int key, t_data *m)
{
	if (key == a && check_safety(m, a) && check_safety1(m, a))
	{
		check_enemy(m, key);
		put_images(m, a);
		m->numberofmovements++;
	}
	else if (key == s && check_safety(m, s) && check_safety1(m, s))
	{
		check_enemy(m, key);
		put_images(m, s);
		m->numberofmovements++;
	}
	else if (key == w && check_safety(m, w) && check_safety1(m, w))
	{
		check_enemy(m, key);
		put_images(m, w);
		m->numberofmovements++;
	}
}

int	key_hook(int key, t_data *m)
{
	if (key == 53)
	{
		m->message = 5;
		ft_exit(m);
	}
	if (key == d && check_safety(m, d) && check_safety1(m, d))
	{
		check_enemy(m, key);
		put_images(m, d);
		m->numberofmovements++;
	}
	key_hook2(key, m);
	if (m->mapinfo.collgot == m->mapinfo.collnumber)
	{
		m->im.i6 = mlx_xpm_file_to_image(m->ml, r5, &m->wt, &m->hg);
	}
	return (1);
}
