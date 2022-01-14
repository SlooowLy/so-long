#include "lib.h"

static int hh = 1;

typedef struct s_map
{
	char	*walls;
	int		wallsnumber;
	char	*door;
	int		doornumber;
	char	*coll;
	int		collnumber;
	int		player;
	int		collgot;
}				t_map;

typedef struct s_image
{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
}				t_image;

typedef struct s_player
{
	int	px;
	int	py;	
}				t_player;

typedef struct s_imageinfo
{
	int	x;
	int	y;	
}				t_imageinfo;

typedef struct	s_data
{
	void		*img;
	int			*addr;
	void		*mlx;
	char		*map;
	t_map		mapinfo;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_image		imgj;
	t_player	player;
	t_imageinfo	imageinfo;
}				t_data;

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

int	check_safety(t_data *data, int i)
{
	int	x;
	char	*walls = data->mapinfo.walls;
	char	*door = data->mapinfo.door;
	char	*coll = data->mapinfo.coll;
	int		player = data->mapinfo.player;

	x = 0;
	// printf ("%d\n", i);
	if (i == d)
		i = 1;
	else if (i == a)
		i = -1;
	else if (i == w)
		i = -1*(data->imageinfo.x+1);
	else if (i == s)
		i = data->imageinfo.x+1;
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

int	check_safety1(t_data *data, int i)
{
	int		x;
	int		ret = 1;
	char	*door = data->mapinfo.door;
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
}

int	key_hook(int key, t_data *data)
{
	int	px = data->player.px;
	int	py = data->player.py;
	static int	i = 1;

	if (key == d && check_safety(data, d) && check_safety1(data, 1))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px+60, data->player.py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, data->player.px+60, data->player.py);
		data->player.px = px+60;
		data->mapinfo.player++;
	}
	else if (key == a && check_safety(data, a) && check_safety1(data, -1))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px-60, data->player.py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, data->player.px-60, data->player.py);
		data->player.px = px-60;
		data->mapinfo.player--;
	}
	else if (key == s && check_safety(data, s) && check_safety1(data, (data->imageinfo.x+1)))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py+60);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, data->player.px, data->player.py+60);
		data->player.py = py+60;
		data->mapinfo.player = 	data->mapinfo.player + data->imageinfo.x + 1;
	}
	else if (key == w && check_safety(data, w) && check_safety1(data, -1*(data->imageinfo.x+1)))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, data->player.px, data->player.py-60);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, data->player.px, data->player.py-60);
		data->player.py = py-60;
		data->mapinfo.player = 	data->mapinfo.player - data->imageinfo.x - 1;
	}
	if (data->mapinfo.collgot == data->mapinfo.collnumber)
		change_door(&*data);
	return (1);
}

int	main(void)
{
 	t_data	data;
	int		fd;
	int		px;
	int		py;
	int		x = 0;
	int		y = 0;
	char	*ret1;
	int		i = 0;
	int		j = 0;

	fd = open ("map.txt", O_RDONLY);
	read_map(&data.map, fd);
	data.mapinfo.wallsnumber = 0;
	data.mapinfo.collnumber = 0;
	data.mapinfo.doornumber = 0;
	data.mapinfo.collgot = 0;
	while (data.map[i])
	{
		if (data.map[i] == '\n')
			j++;
		if (data.map[i] == 49)
			data.mapinfo.wallsnumber++;
		if (data.map[i] == 67)
			data.mapinfo.collnumber++;
		if (data.map[i] == 80)
			data.mapinfo.player = i;
		if (data.map[i] == 69)
			data.mapinfo.doornumber++;
		i++;
	}
	data.mapinfo.walls = malloc (data.mapinfo.wallsnumber+1);
	data.mapinfo.coll = malloc (data.mapinfo.collnumber+1);
	data.mapinfo.door = malloc (data.mapinfo.doornumber+1);
	data.mapinfo.wallsnumber = 0;
	data.mapinfo.collnumber = 0;
	data.mapinfo.doornumber = 0;
	j++;
	data.mlx = mlx_init();
	data.imageinfo.x = i/j;
	data.imageinfo.y = j;
	data.mlx_win = mlx_new_window(data.mlx, ((i/j)*60), j*60, "So_long");
	data.imgj.img1 = mlx_xpm_file_to_image(data.mlx, relative_path, &data.img_width, &data.img_height);
	data.imgj.img2 = mlx_xpm_file_to_image(data.mlx, relative_path2, &data.img_width, &data.img_height);
	data.imgj.img3 = mlx_xpm_file_to_image(data.mlx, relative_path3, &data.img_width, &data.img_height);
	data.imgj.img4 = mlx_xpm_file_to_image(data.mlx, relative_path4, &data.img_width, &data.img_height);
	data.imgj.img5 = mlx_xpm_file_to_image(data.mlx, relative_path5, &data.img_width, &data.img_height);
	data.imgj.img6 = mlx_xpm_file_to_image(data.mlx, relative_path6, &data.img_width, &data.img_height);
	i = 0;
	while (data.map[i] && hh)
	{
		if (data.map[i] == 49)
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img1, x, y);
			data.mapinfo.walls[data.mapinfo.wallsnumber++] = i;
		}
		else if (data.map[i] == 48)
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img2, x, y);
		else if (data.map[i] == 80)
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img2, x, y);
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img3, x, y);
			data.player.px = x;
			data.player.py = y;
		}
		else if (data.map[i] == 67)
		{
			data.mapinfo.coll[data.mapinfo.collnumber++] = i;
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img2, x, y);
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img4, x, y);
		}
		else if (data.map[i] == 69)
		{
			data.mapinfo.door[data.mapinfo.doornumber++] = i;
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img2, x, y);
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img6, x, y);
		}
		if (data.map[i] == 10)
		{
			x = 0;
			y += 60;
		}
		else
			x += 60;
		i++;
	}
	hh = 0;
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
}