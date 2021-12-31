#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
int	x1 = 50;
int	y1 = 50;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	int		x = 0;
	int		y = 0;
	void	*mlx_win;
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	while (y <= y1)
	{

		my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
		if (x == x1)
		{
			y++;
			x = 0;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}