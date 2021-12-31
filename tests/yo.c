#include <mlx.h>

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x;
	int	y;

	y = 100;
	x = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2000, 900, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	while (y < 300)
	{
		img.addr[x * 400 + y] = 0x00FFFFFF;
		if (x == 300)
		{
			y++;
			x = 100;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}