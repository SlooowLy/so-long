#include "lib.h"

int	check_numbers(t_data *data, int *j)
{
	int	i;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
			j++;
		if (data->map[i] == 49)
			data->mapinfo.wallsnumber++;
		if (data->map[i] == 67)
			data->mapinfo.collnumber++;
		if (data->map[i] == 80)
			data->mapinfo.player = i;
		if (data->map[i] == 69)
			data->mapinfo.doornumber++;
		i++;
	}
	j++;
}

void	creat_images_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, ((data->i/data->j)*60), data->j*60, "So_long");
	data->imgj.img1 = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
	data->imgj.img2 = mlx_xpm_file_to_image(data->mlx, relative_path2, &data->img_width, &data->img_height);
	data->imgj.img3 = mlx_xpm_file_to_image(data->mlx, relative_path3, &data->img_width, &data->img_height);
	data->imgj.img4 = mlx_xpm_file_to_image(data->mlx, relative_path4, &data->img_width, &data->img_height);
	data->imgj.img5 = mlx_xpm_file_to_image(data->mlx, relative_path5, &data->img_width, &data->img_height);
	data->imgj.img6 = mlx_xpm_file_to_image(data->mlx, relative_path6, &data->img_width, &data->img_height);
}

int	print_map2(t_data *data, int x, int y, int i)
{
	if (data->map[i] == 80)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, x, y);
		data->player.px = x;
		data->player.py = y;
	}
	else if (data->map[i] == 67)
	{
		data->mapinfo.coll[data->mapinfo.collnumber++] = i;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img4, x, y);
	}
	else if (data->map[i] == 69)
	{
		data->mapinfo.door[data->mapinfo.doornumber++] = i;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img6, x, y);
	}
	return (i);
}

void	print_map1(t_data *data, int x, int y, int i)
{
	while (data->map[i])
	{
		if (data->map[i] == 49)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img1, x, y);
			data->mapinfo.walls[data->mapinfo.wallsnumber++] = i;
		}
		else if (data->map[i] == 48)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
		else if (data->map[i] == 80 || data->map[i] == 67 || data->map[i] == 69)
			i = print_map2(data, x, y, i);
		if (data->map[i] == 10)
		{
			x = 0;
			y += 60;
		}
		else
			x += 60;
		i++;
	}
}

int	main(void)
{
 	t_data	data;
	int		x;
	int		y;

	x = 0;
	y = 0;
	read_map(&data.map, open ("map.txt", O_RDONLY));
    give_null_value(&data);
	data.i = check_numbers(&data, &data.j);
	allocating(&data);
    give_null_value(&data);
	data.mlx = mlx_init();
	data.imageinfo.x = data.i/data.j;
	data.imageinfo.y = data.j;
	creat_images_window(&data);
	print_map1(&data, x, y, 0);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
}