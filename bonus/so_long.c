#include "lib.h"

void	creat_images_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->i*60, data->j*60, "So_long");
	data->imgj.img1 = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
	data->imgj.img2 = mlx_xpm_file_to_image(data->mlx, relative_path2, &data->img_width, &data->img_height);
	data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_d, &data->img_width, &data->img_height);
	data->imgj.img4 = mlx_xpm_file_to_image(data->mlx, relative_path4, &data->img_width, &data->img_height);
	data->imgj.img5 = mlx_xpm_file_to_image(data->mlx, relative_path5, &data->img_width, &data->img_height);
	data->imgj.img6 = mlx_xpm_file_to_image(data->mlx, relative_path6, &data->img_width, &data->img_height);
	data->imgj.kha = mlx_xpm_file_to_image(data->mlx, relative_path_kha_d, &data->img_width, &data->img_height);
	data->imgj.rammus = mlx_xpm_file_to_image(data->mlx, relative_path_rammus_a, &data->img_width, &data->img_height);
}

void	print_map1(t_data *data)
{
	int	k = 0;
	int	j = 0;
	int i = 0;
	int x = 0;
	int y = 0;

	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 49)
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img1, x, y);
			else if (data->map[i][j] == 48)
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
			if (data->map[i][j] == 80)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_d, x, y);
			}
			else if (data->map[i][j] == 67)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img4, x, y);
				data->mapinfo.collnumber++;
			}
			else if (data->map[i][j] == 69)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img6, x, y);
			}
			else if (data->map[i][j] == 'X')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.rammus, x, y);
			}
			x += 60;
			j++;
		}
		x = 0;
		y += 60;
		i++;
		j = 0;
	}
}

void	change_player(t_data *data)
{
	static int	i = 11;
	int h;
	
	if (!data->player_eve)
	{
		if (i)
		{
			usleep (100000);
			if (i % 2)
				data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_evolved, &data->img_width, &data->img_height);
			else
				data->imgj.img_d = mlx_xpm_file_to_image(data->mlx, relative_kha_d, &data->img_width, &data->img_height);
			i--;
			if (!i)
				data->player_eve = 3;
		}
	}
}

void	do_movements(t_data *data, int j, int k, int i)
{
	if (i % 2 && (data->map[j][k - 1] == '0' || data->map[j][k - 1] == 'P'))
	{
		if (data->map[j][k - 1] == 'P')
		{
			data->message = 1;
			ft_exit(data);
		}
		data->imgj.rammus = mlx_xpm_file_to_image(data->mlx, relative_path_rammus_a, &data->img_width, &data->img_height);
		data->map[j][k] = '0';
		data->map[j][k - 1] = 'X';
	}
	else if (data->map[j][k + 1] == '0' || data->map[j][k + 1] == 'P')
	{
		if (data->map[j][k + 1] == 'P')
		{
			data->message = 1;
			ft_exit(data);
		}
		data->imgj.rammus = mlx_xpm_file_to_image(data->mlx, relative_path_rammus_d, &data->img_width, &data->img_height);
		data->map[j][k] = '0';
		data->map[j][k + 1] = 'X';
	}
}

void	change_rammus(t_data *data)
{
	static int	i = 1;
	int	j;
	int	k;

	j = 0;
	while (data->map[j])
	{
		k = 0;
		while (data->map[j][k])
		{
			if (data->map[j][k] == 'X')
			{
				do_movements(data, j, k, i);
				i++;
				break;
			}
			k++;
		}
		j++;
	}
	i++;
	if (i == 100000)
		i = 1;
	usleep(100000);
}

char	*put_string(int	num)
{
	int	i;
	int	n;
	char	*r;

	i = 0; 
	n = num;
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	r = malloc(i);
	i = 0;
	printf("%d\n", n);
	while (num > 9)
	{
		r[i] = n / 10 + 48;
		n = n % 10;
		i++;
	}
	r[i] = n + 48;
	write(1, &r[0], 1);
	return (r);
}

int	render_next_frame(t_data *data)
{
	int	k = 0;
	int	j = 0;
	int i = 0;
	int x = 0;
	int y = 0;

	change_player(data);
	change_rammus(data);
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 49)
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img1, x, y);
			else if (data->map[i][j] == 48)
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
			if (data->map[i][j] == 80)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img_d, x, y);
			}
			else if (data->map[i][j] == 67)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img4, x, y);
			}
			else if (data->map[i][j] == 69)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img6, x, y);
			}
			else if (data->map[i][j] == 'X')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, x, y);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.rammus, x, y);
			}
			x += 60;
			j++;
		}
		x = 0;
		y += 60;
		i++;
		j = 0;
	}
	mlx_string_put(data->mlx, data->mlx_win, 0, 0, 0XFF0000, ft_itoa(data->numberofmovements));
	return (1);
}

int	main(int ac, char **av)
{
 	t_data	data;
	int		fd;
	int	x = 0;
	int	y = 0;

	if (ac != 2)
		arg_error(&data);
	if (ft_strncmp(&av[1][len(av[1]) - 4], ".ber", 4))
		map_error(&data);
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
		map_error(&data);
	data.map_d = NULL;
	read_map(&data.map_d, fd);
	if (!(len(data.map_d)))
		map_error(&data);
	data.mapinfo.collgot = 0;
	data.message = 0;
	data.mapinfo.collnumber = 0;
	data.numberofmovements = 1;
	data.player_eve = 1;
	data.map = ft_split(data.map_d, '\n');
	data.mlx = mlx_init();
	if (!check_map(data.map, data.map_d))
		map_error(&data);
	data.i = len(data.map[0]);
	data.j = check_len(data.map);
	creat_images_window(&data);
	print_map1(&data);
	mlx_hook(data.mlx_win, 2, 1L<<0, key_hook, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_hook(data.mlx_win, 17, 1L<<17, ft_exit, &data);
	mlx_loop(data.mlx);
}