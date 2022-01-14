#include "lib.h"

int	check_safety(t_data *data, int i)
{
	int	x;
	int	y;
	int	j;
	char	m;

	j = 1;
	x = 0;
	while (data->map[x] && j)
	{
		y = 0;
		while (data->map[x][y] && j)
		{
			if (data->map[x][y] == 'P')
			{
				j = 0;
			}
			y++;
		}
		x++;
	}
	x--;
	y--;
	if (i == d)
		m = data->map[x][y + 1];
	if (i == a)
		m = data->map[x][y - 1];
	if (i == s)
		m = data->map[x + 1][y];
	if (i == w)
		m = data->map[x - 1][y];
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
	mlx_clear_window(data->mlx, data->mlx_win);
	free (data->map_d);
	ft_free(data->map);
	exit(0);
}

int	check_safety1(t_data *data, int i)
{
	int	x;
	int	y;
	int	j;
	char	m;

	j = 1;
	x = 0;
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
	if (i == d)
		m = data->map[x][y + 1];
	else if (i == a)
		m = data->map[x][y - 1];
	else if (i == s)
		m = data->map[x + 1][y];
	else if (i == w)
		m = data->map[x - 1][y];
	if (m == 'E')
	{
		if (data->mapinfo.collnumber == data->mapinfo.collgot)
		{
			destroy_all(data);
		}
		return (0);
	}
	return (1);
}

int	check_enemy(t_data *data, int i)
{
	int	x;
	int	y;
	int	j;
	char	m;

	j = 1;
	x = 0;
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
	if (i == d)
		m = data->map[x][y + 1];
	else if (i == a)
		m = data->map[x][y - 1];
	else if (i == s)
		m = data->map[x + 1][y];
	else if (i == w)
		m = data->map[x - 1][y];
	if (m == 'X')
	{
		data->message = 1;
		ft_exit(data);
		return (0);
	}
	return (1);
}

void player_animation(int key, t_data *data)
{
	if (key == d && data->player_eve != 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_d, &data->img_width, &data->img_height);
	if (key == w && data->player_eve != 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_w, &data->img_width, &data->img_height);
	if (key == a && data->player_eve != 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_a, &data->img_width, &data->img_height);
	if (key == s && data->player_eve != 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_s, &data->img_width, &data->img_height);
	if (key == d && data->player_eve == 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_path_kha_d, &data->img_width, &data->img_height);
	if (key == w && data->player_eve == 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_path_kha_w, &data->img_width, &data->img_height);
	if (key == a && data->player_eve == 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_path_kha_a, &data->img_width, &data->img_height);
	if (key == s && data->player_eve == 3)
		data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_path_kha_s, &data->img_width, &data->img_height);
}

void    put_images(t_data *data, int key)
{
	int	x;
	int	y;
	int	j;

	j = 1;
	x = 0;
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

int	key_hook(int key, t_data *data)
{
	static int	i = 1;

	if (key == 53)
		destroy_all(data);
	if (key == d && check_safety(data, d) && check_safety1(data, d))
	{
		check_enemy(data, key);
		put_images(data, d);
		data->numberofmovements++;
	}
	else if (key == a && check_safety(data, a) && check_safety1(data, a))
	{
		check_enemy(data, key);
		put_images(data, a);
		data->numberofmovements++;
	}
	else if (key == s && check_safety(data, s) && check_safety1(data, s))
	{
		check_enemy(data, key);
		put_images(data, s);
		data->numberofmovements++;
	}
	else if (key == w && check_safety(data, w) && check_safety1(data, w))
	{
		check_enemy(data, key);
		put_images(data, w);
		data->numberofmovements++;
	}
	if (data->mapinfo.collgot == data->mapinfo.collnumber)
	{
		data->imgj.img6 = mlx_xpm_file_to_image(data->mlx, relative_path5, &data->img_width, &data->img_height);
	}
	return (1);
}