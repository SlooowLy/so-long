/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:42:46 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 19:42:47 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	player_animation(int key, t_data *m)
{
	if (key == d && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, khad, &m->wt, &m->hg);
	if (key == w && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, khaw, &m->wt, &m->hg);
	if (key == a && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, khaa, &m->wt, &m->hg);
	if (key == s && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, khas, &m->wt, &m->hg);
	if (key == d && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, ekhad, &m->wt, &m->hg);
	if (key == w && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, ekhaw, &m->wt, &m->hg);
	if (key == a && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, ekhaa, &m->wt, &m->hg);
	if (key == s && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, ekhas, &m->wt, &m->hg);
}

void	render_next_frame_2(t_data *m)
{
	if (m->map[m->n.i][m->n.j] == 48)
		mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
	if (m->map[m->n.i][m->n.j] == 80)
	{
		mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
		mlx_put_image_to_window(m->ml, m->wi, m->im.id, m->n.x, m->n.y);
	}
	else if (m->map[m->n.i][m->n.j] == 67)
	{
		mlx_put_image_to_window(m->ml, m->wi, m->im.i2, m->n.x, m->n.y);
		mlx_put_image_to_window(m->ml, m->wi, m->im.i4, m->n.x, m->n.y);
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
