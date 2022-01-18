/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:16:13 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:16:15 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	creat_images_window(t_data *m)
{
	m->wi = mlx_new_window(m->ml, m->i * 60, m->j * 60, "So_long");
	m->im.i1 = mlx_xpm_file_to_image(m->ml, relative_path, &m->wt, &m->hg);
	m->im.i2 = mlx_xpm_file_to_image(m->ml, relative_path2, &m->wt, &m->hg);
	m->im.id = mlx_xpm_file_to_image(m->ml, khad, &m->wt, &m->hg);
	m->im.i4 = mlx_xpm_file_to_image(m->ml, relative_path4, &m->wt, &m->hg);
	m->im.i5 = mlx_xpm_file_to_image(m->ml, r5, &m->wt, &m->hg);
	m->im.i6 = mlx_xpm_file_to_image(m->ml, r6, &m->wt, &m->hg);
	m->im.kha = mlx_xpm_file_to_image(m->ml, ekhad, &m->wt, &m->hg);
	m->im.rm = mlx_xpm_file_to_image(m->ml, musa, &m->wt, &m->hg);
}

void	print_map2(t_data *m)
{
	if (m->map[m->n.i][m->n.j] == 80)
	{
		mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
		mlx_put_image_to_window(m->ml, m->wi, m->im.id, m->n.x, m->n.y);
	}
	else if (m->map[m->n.i][m->n.j] == 67)
	{
		mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
		mlx_put_image_to_window(m->ml, m->wi, m->im.i4, m->n.x, m->n.y);
		m->mapinfo.collnumber++;
	}
	else if (m->map[m->n.i][m->n.j] == 69)
	{
		mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
		mlx_put_image_to_window(m->ml, m->wi, m->im.i6, m->n.x, m->n.y);
	}
}

void	print_map1(t_data *m)
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
			else if (m->map[m->n.i][m->n.j] == 48)
				mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
			print_map2(m);
			m->n.x += 60;
			m->n.j++;
		}
		m->n.x = 0;
		m->n.y += 60;
		m->n.i++;
		m->n.j = 0;
	}
}

void	change_player(t_data *m)
{
	static int	i = 11;

	if (!m->player_eve)
	{
		if (i)
		{
			if (i % 2)
				m->im.id = mlx_xpm_file_to_image(m->ml, ekha, &m->wt, &m->hg);
			else
				m->im.id = mlx_xpm_file_to_image(m->ml, khad, &m->wt, &m->hg);
			i--;
			if (!i)
				m->player_eve = 3;
		}
	}
}
