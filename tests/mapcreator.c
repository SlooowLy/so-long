#include "lib.h"
// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	int		*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int	x;
// 	int	y;
//     char	*relative_path = "./imagetesst.xpm";
// 	int		img_width = 54;
// 	int		img_height = 50;

// 	y = 100;
// 	x = 100;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
// 	img.img = mlx_new_image(mlx, 400, 400);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
static int hh = 1;

typedef struct s_map
{
	char	*walls;
	int	wallsnumber;
	char	*dor;
	int	dornumber;
	char	*coll;
	int	collnumber;
	int	player;
}				t_map;

typedef struct s_image
{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;	
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

int	check_safety(t_data *data, int i, int c)
{
	int	x;
	char	*walls = data->mapinfo.walls;
	int		player = data->mapinfo.player;

	x = 0;
	// printf ("%d\n", walls[x]);
	// printf ("%d\n", player);
	// printf ("%s\n", "yo");
	while (x < player)
	{
		// printf ("%d\n", walls[x]);
		if (walls[x] == player + i)
			return (0);
		x++;
	}
	return (1);
}

int	key_hook(int key,t_data *data)
{
	int	px = data->player.px;
	int	py = data->player.py;

	if (key == d && check_safety(&*data, 1, 1))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, px, py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, px+60, py);
		data->player.px = px+60;
		data->mapinfo.player++;
	}
	else if (key == a && check_safety(&*data, -1, 1))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, px, py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, px-60, py);
		data->player.px = px-60;
		data->mapinfo.player--;
	}
	else if (key == s && check_safety(&*data, data->imageinfo.x+1, 1))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, px, py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, px, py+60);
		data->player.py = py+60;
		data->mapinfo.player = 	data->mapinfo.player + data->imageinfo.x + 1;
	}
	else if (key == w && check_safety(&*data, -1*(data->imageinfo.x+1), 1))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img2, px, py);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgj.img3, px, py-60);
		data->player.py = py-60;
		data->mapinfo.player = 	data->mapinfo.player - data->imageinfo.x - 1;
	}
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
	read_map(&ret1, fd);
	data.mapinfo.wallsnumber = 0;
	data.mapinfo.collnumber = 0;
	data.mapinfo.dornumber = 0;
	while (ret1[i])
	{
		if (ret1[i] == '\n')
			j++;
		if (ret1[i] == 49)
			data.mapinfo.wallsnumber++;
		if (ret1[i] == 67)
			data.mapinfo.collnumber++;
		if (ret1[i] == 80)
			data.mapinfo.player = i;
		i++;
	}
	data.mapinfo.walls = malloc (data.mapinfo.wallsnumber);
	data.mapinfo.coll = malloc (data.mapinfo.collnumber);
	// printf ("%d\n", data.p);
	// printf ("%d\n", data.mapinfo.collnumber);
	// printf ("%d\n", j*60);
	// printf ("%d\n", ((i/j)*60));
	data.mapinfo.wallsnumber = 0;
	data.mapinfo.collnumber = 0;
	j++;
	data.map = ret1;
	data.mlx = mlx_init();
	data.imageinfo.x = i/j;
	data.imageinfo.y = j;
	data.mlx_win = mlx_new_window(data.mlx, ((i/j)*60), j*60, "Hello world!");
	data.imgj.img1 = mlx_xpm_file_to_image(data.mlx, relative_path, &data.img_width, &data.img_height);
	data.imgj.img2 = mlx_xpm_file_to_image(data.mlx, relative_path2, &data.img_width, &data.img_height);
	data.imgj.img3 = mlx_xpm_file_to_image(data.mlx, relative_path3, &data.img_width, &data.img_height);
	data.imgj.img4 = mlx_xpm_file_to_image(data.mlx, relative_path4, &data.img_width, &data.img_height);
	i = 0;
	while (ret1[i] && hh)
	{
		if (ret1[i] == 49)
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img1, x, y);
			data.mapinfo.walls[data.mapinfo.wallsnumber++] = i;
		}
		else if (ret1[i] == 48)
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img2, x, y);
		else if (ret1[i] == 80)
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img2, x, y);
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img3, x, y);
			data.player.px = x;
			data.player.py = y;
		}
		else if (ret1[i] == 67)
		{
			data.mapinfo.coll[data.mapinfo.collnumber++] = i;
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img2, x, y);
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgj.img4, x, y);
		}
		if (ret1[i] == 10)
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