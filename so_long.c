/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:16:01 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:16:02 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

int	render_next_frame(t_data *m)
{
	m->n.k = 0;
	m->n.j = 0;
	m->n.i = 0;
	m->n.x = 0;
	m->n.y = 0;
	while (m->map[m->n.i])
	{
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
		m->n.j = 0;
	}
	return (1);
}

void	give_value(t_data *data)
{
	data->mapinfo.collgot = 0;
	data->message = 0;
	data->mapinfo.collnumber = 0;
	data->numberofmovements = 1;
}

void	map_message(t_data *data)
{
	if (!(data->map))
		map_error(data);
	if (!check_map(data->map, data->map_d))
		map_error(data);
	if (!(len(data->map_d)))
		map_error(data);
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
		arg_error(&data);
	if (ft_strncmp(&av[1][len(av[1]) - 4], ".ber", 4))
		map_error(&data);
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
		map_error(&data);
	fd = read_map(&data.map_d, fd);
	check_map_error(fd, &data);
	give_value(&data);
	data.map = ft_split(data.map_d, '\n');
	map_message(&data);
	data.ml = mlx_init();
	data.i = len(data.map[0]);
	data.j = check_len(data.map);
	creat_images_window(&data);
	print_map1(&data);
	mlx_hook(data.wi, 2, 1L << 0, key_hook, &data);
	mlx_loop_hook(data.ml, render_next_frame, &data);
	mlx_hook(data.wi, 17, 1L << 17, ft_exit, &data);
	mlx_loop(data.ml);
}
