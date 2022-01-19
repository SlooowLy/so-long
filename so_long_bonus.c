/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:02:44 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:02:48 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

int	check_r(void)
{
	static int	k;

	while (!(++k % 50))
	{
		if (k == 100000)
			k = 0;
		return (1);
	}
	return (0);
}

void	change_rammus(t_data *data)
{
	int	j;
	int	k;

	j = 0;
	while (data->map[j])
	{
		k = 0;
		while (data->map[j][k])
		{
			if (data->map[j][k] == 'X' && check_r ())
			{
				do_movements(data, j, k);
			}
			k++;
		}
		j++;
	}
}

int	render_next_frame(t_data *m)
{
	change_rammus(m);
	change_player(m);
	m->n.k = 0;
	m->n.i = 0;
	m->n.x = 0;
	m->n.y = 0;
	while (m->map[m->n.i])
	{
		m->n.j = 0;
		while (m->map[m->n.i][m->n.j])
		{
			if (m->map[m->n.i][m->n.j] == 49)
				mlx_put_image_to_window(m->ml, m->wi, m->im.i1, m->n.x, m->n.y);
			render_next_frame_2(m);
			m->n.x += 60;
			m->n.j++;
		}
		m->n.x = 0;
		m->n.y += 60;
		m->n.i++;
	}
	if (!(ft_itoa(m->numberofmovements, m)))
		ft_exit (m);
	return (1);
}

void	check_map_error(int i, t_data *data)
{
	if (i == 0)
		map_error(data);
	if (i == 2)
		map_error(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2)
	{
		data.message = 3;
		ft_exit(&data);
	}
	if (ft_strncmp(&av[1][len(av[1]) - 4], ".ber", 4))
		map_error(&data);
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
		map_error(&data);
	fd = read_map(&data.map_d, fd);
	check_map_error(fd, &data);
	data.map = ft_split(data.map_d, '\n');
	map_message(&data);
	give_value(&data);
	data.ml = mlx_init();
	creat_images_window(&data);
	print_map1(&data);
	mlx_hook(data.wi, 2, 1L << 0, key_hook, &data);
	mlx_loop_hook(data.ml, render_next_frame, &data);
	mlx_hook(data.wi, 17, 1L << 17, ft_exit, &data);
	mlx_loop(data.ml);
}
