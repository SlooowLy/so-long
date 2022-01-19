/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:15:15 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:15:16 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	player_animation(int key, t_data *m)
{
	if (key == D && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, KHAD, &m->wt, &m->hg);
	if (key == W && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, KHAW, &m->wt, &m->hg);
	if (key == A && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, KHAA, &m->wt, &m->hg);
	if (key == S && m->player_eve != 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, KHAS, &m->wt, &m->hg);
	if (key == D && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, EKHAD, &m->wt, &m->hg);
	if (key == W && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, EKHAW, &m->wt, &m->hg);
	if (key == A && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, EKHAA, &m->wt, &m->hg);
	if (key == S && m->player_eve == 3)
		m->im.id = mlx_xpm_file_to_image(m->ml, EKHAS, &m->wt, &m->hg);
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
