#include "lib.h"

int	check_numbers(t_data *data)
{
	int	i;
	int	j;

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
	data->j = j;
	return (i);
}

void	creat_images_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, ((data->i/data->j)*60), data->j*60, "So_long");
	data->imgj.img1 = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
	data->imgj.img2 = mlx_xpm_file_to_image(data->mlx, relative_path2, &data->img_width, &data->img_height);
	data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_d, &data->img_width, &data->img_height);
	data->imgj.img_a = mlx_xpm_file_to_image(data->mlx, relative_kha_a, &data->img_width, &data->img_height);
	data->imgj.img_w = mlx_xpm_file_to_image(data->mlx, relative_kha_w, &data->img_width, &data->img_height);
	data->imgj.img_s = mlx_xpm_file_to_image(data->mlx, relative_kha_s, &data->img_width, &data->img_height);
	data->imgj.img_evolved = mlx_xpm_file_to_image(data->mlx, relative_kha_evolved, &data->img_width, &data->img_height);
	data->imgj.img4 = mlx_xpm_file_to_image(data->mlx, relative_path4, &data->img_width, &data->img_height);
	data->imgj.img5 = mlx_xpm_file_to_image(data->mlx, relative_path5, &data->img_width, &data->img_height);
	data->imgj.img6 = mlx_xpm_file_to_image(data->mlx, relative_path6, &data->img_width, &data->img_height);
}

int	print_map2(t_data *data, int x, int y, int i)
{
	if (data->map[i] == 80)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_d, x, y);
		data->player.px = x;
		data->player.py = y;
	}
	else if (data->map[i] == 67)
	{
		data->mapinfo.coll[data->mapinfo.collnumber] = i;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img4, x, y);
		data->mapinfo.collnumber += 1;
	}
	else if (data->map[i] == 69)
	{
		data->mapinfo.door[data->mapinfo.doornumber] = i;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img6, x, y);
		data->mapinfo.doornumber++;;
	}
	return (i);
}

void	print_map1(t_data *data, int x, int y, int i)
{
	int	k = 0;
	while (data->map[i])
	{
		if (data->map[i] == 49)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img1, x, y);
			data->mapinfo.walls[k++] = i;
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

void	printf_mappp(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		write (1, &map[i], 1);
		i++;
	}
}
int	main(void)
{
 	t_data	data;
	int		x;
	int		y;
	int		fd;

	x = 0;
	y = 0;
	data.i = 0;
    data.j = 0;
	data.player_eve = 0;
    data.mapinfo.wallsnumber = 0;
	fd = open ("map.txt", O_RDONLY);
	read_map(&data.map, fd);
    give_null_value(&data);
	data.i = check_numbers(&data);
	allocating(&data);
    give_null_value(&data);
	data.mlx = mlx_init();
	data.imageinfo.x = data.i/data.j;
	data.imageinfo.y = data.j;
	printf ("%d\n", check_map(data.map));
	creat_images_window(&data);
	print_map1(&data, x, y, 0);
	mlx_hook(data.mlx_win, 2, 1L<<0, key_hook, &data);
	mlx_loop(data.mlx);
}