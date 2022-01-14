#include "lib.h"

int	check_safety(t_data *data, int i)
{
	int	x;
	int	*walls = data->mapinfo.walls;
	int	*door = data->mapinfo.door;
	int	*coll = data->mapinfo.coll;
	int		player = data->mapinfo.player;

	x = 0;
	if (i == d)
		i = 1;
	else if (i == a)
		i = -1;
	else if (i == w)
		i = -1*(data->imageinfo.x+1);
	else if (i == s)
		i = (data->imageinfo.x+1);
	else
		return (0);
	while (x < data->mapinfo.collnumber && data->mapinfo.collgot != data->mapinfo.collnumber)
	{
		if (coll[x] == player + i)
		{
			coll[x] = -1;
			data->mapinfo.collgot++;
		}
		x++;
	}
	x = 0;
	while (x < data->mapinfo.wallsnumber)
	{
		if (walls[x] == player + i)
			return (0);
		x++;
	}
	return (1);
}

// void	change_player(t_data *data, int key)
// {
// 	static int	i;
// 	int h;
	
// 	i = 3;
// 	if (!data->player_eve)
// 	{
// 		if (i)
// 		{
// 			usleep (500000);
// 			if (i % 2)
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_a, data->player.px, data->player.py);
// 			else
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_evolved, data->player.px, data->player.py);
// 			i--;
// 			mlx_loop(mlx_init());
// 		}
// 	}
// }

void	change_door(t_data *data)
{
	int	x = 0;
	int	px = 0;
	int	py = 0;
	int	n = 0;
	int	ret = 0;
	char	*map = data->map;

	while (map[x])
	{
		if (map[x] == 'E')
		{
			if (n > data->imageinfo.x)
			{
				px = n % data->imageinfo.x;
				py = n / data->imageinfo.x;
			}
			else
			{
				px = n;
				py = 0;
			}
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, px*60, py*60);
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img5, px*60, py*60);
		}
		if (map[x] != 10)
			n++;
		x++;
	}
	// change_player(data, key);
}

void	destroy_all(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->imgj.img1);
	// mlx_destroy_image(data->mlx, data->imgj.img2);
	// mlx_destroy_image(data->mlx, data->imgj.img3);
	// mlx_destroy_image(data->mlx, data->imgj.img4);
	// mlx_destroy_image(data->mlx, data->imgj.img5);
	// mlx_destroy_image(data->mlx, data->imgj.img6);
	// mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_clear_window(data->mlx, data->mlx_win);
	exit (0);
}

int	check_safety1(t_data *data, int i)
{
	int		x;
	int		ret = 1;
	int		*door = data->mapinfo.door;
	int		player = data->mapinfo.player;

	x = 0;
	while (x < data->mapinfo.doornumber)
	{
		if (door[x] != player + i)
			ret = 1;
		else
		{
			if (data->mapinfo.collnumber == data->mapinfo.collgot)
				destroy_all(data);
			return (0);
		}
		x++;
	}
	return (ret);
}

void	change_player(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (i%2)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_evolved, data->player.px, data->player.py);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_d, data->player.px, data->player.py);
		usleep(500000);
		i++;
	}
}

void player_animation(int key, t_data *data)
{
	if (key == d)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_d, data->player.px, data->player.py);
	if (key == w)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_w, data->player.px, data->player.py);
	if (key == a)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_a, data->player.px, data->player.py);
	if (key == s)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_s, data->player.px, data->player.py);
}

void    put_images(t_data *data, int key)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py);
	if (key == d)
	{
		data->player.px = data->player.px+60;
		data->mapinfo.player++;
	}
	else if (key == a)
	{
		data->player.px = data->player.px-60;
		data->mapinfo.player--;
	}
	else if (key == s)
	{
		data->player.py = data->player.py+60;
		data->mapinfo.player = 	data->mapinfo.player + data->imageinfo.x + 1;
	}
	else if (key == w)
	{
		data->player.py = data->player.py-60;
		data->mapinfo.player = 	data->mapinfo.player - data->imageinfo.x - 1;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py);
	player_animation(key, data);
}

int	key_hook(int key, t_data *data)
{
	static int	i = 1;

	if (key == 53)
		destroy_all(data);
	if (key == d && check_safety(data, d) && check_safety1(data, 1))
	{
		put_images(data, d);
		ft_printf_d(data->numberofmovements, 1);
		data->numberofmovements++;
	}
	else if (key == a && check_safety(data, a) && check_safety1(data, -1))
	{
		put_images(data, a);
		ft_printf_d(data->numberofmovements, 1);
		data->numberofmovements++;
	}
	else if (key == s && check_safety(data, s) && check_safety1(data, (data->imageinfo.x+1)))
	{
		put_images(data, s);
		ft_printf_d(data->numberofmovements, 1);
		data->numberofmovements++;
	}
	else if (key == w && check_safety(data, w) && check_safety1(data, -1*(data->imageinfo.x+1)))
	{
		put_images(data, w);
		ft_printf_d(data->numberofmovements, 1);
		data->numberofmovements++;
	}
	if (data->mapinfo.collgot == data->mapinfo.collnumber)
	{
		change_door(data);
		change_player(data);
	}
	return (1);
}