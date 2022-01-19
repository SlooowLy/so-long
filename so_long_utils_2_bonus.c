/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:03:01 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:03:02 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

void	creat_images_window(t_data *m)
{
	m->wi = mlx_new_window(m->ml, m->i * 60, m->j * 60, "So_long");
	m->im.i1 = mlx_xpm_file_to_image(m->ml, R, &m->wt, &m->hg);
	m->im.i2 = mlx_xpm_file_to_image(m->ml, R2, &m->wt, &m->hg);
	m->im.id = mlx_xpm_file_to_image(m->ml, KHAD, &m->wt, &m->hg);
	m->im.i4 = mlx_xpm_file_to_image(m->ml, R4, &m->wt, &m->hg);
	m->im.i5 = mlx_xpm_file_to_image(m->ml, R5, &m->wt, &m->hg);
	m->im.i6 = mlx_xpm_file_to_image(m->ml, R6, &m->wt, &m->hg);
	m->im.kha = mlx_xpm_file_to_image(m->ml, EKHAD, &m->wt, &m->hg);
	m->im.rm = mlx_xpm_file_to_image(m->ml, MUSA, &m->wt, &m->hg);
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
	else if (m->map[m->n.i][m->n.j] == 'X')
	{
		mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
		mlx_put_image_to_window(m->ml, m->wi, m->im.rm, m->n.x, m->n.y);
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
				m->im.id = mlx_xpm_file_to_image(m->ml, EKHAA, &m->wt, &m->hg);
			else
				m->im.id = mlx_xpm_file_to_image(m->ml, KHAD, &m->wt, &m->hg);
			i--;
			if (!i)
				m->player_eve = 3;
		}
	}
}

void	do_movements(t_data *m, int j, int k)
{
	int		r;

	while (1)
	{
		r = get_r();
		if (f_u_25line(m, r, j, k) == '0' || f_u_25line(m, r, j, k) == 'P')
		{
			if (f_u_25line(m, r, j, k) == 'P')
			{
				m->message = 1;
				ft_exit(m);
			}
			m->im.rm = mlx_xpm_file_to_image(m->ml, MUSD, &m->wt, &m->hg);
			m->map[j][k] = '0';
			change_player_next_position(m, j, k, r);
			break ;
		}
	}
}
