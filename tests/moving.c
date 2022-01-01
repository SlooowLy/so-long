#include "lib.h"

int	x1 = 50;
int	y1 = 50;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	void	*mlx_win;
	void	*mlx;
	int		img_width;
	int		img_height;
	void	*img1;
	void	*img2;
}				t_data;

int	key_hook(int key, t_data *data)
{
	if (key == w)
		mlx_destroy_image(data->mlx, data->img1);
	else
		mlx_destroy_image(data->mlx, data->img2);
	data->img1 = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1, 120, 120);
}

int	main(void)
{
	int		x = 0;
	int		y = 0;
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 400, 400, "Hello world!");
	data.img = mlx_new_image(data.mlx, 400, 400);
	data.img1 = mlx_xpm_file_to_image(data.mlx, relative_path, &data.img_width, &data.img_height);
	data.img2 = mlx_xpm_file_to_image(data.mlx, relative_path2, &data.img_width, &data.img_height);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img1, 0, 0);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img2, 60, 60);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
}