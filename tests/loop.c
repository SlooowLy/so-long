#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

void	*mlx;
void	*mlx_win;
int		x1 = 50;
int		y1 = 50;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	key_hook(int keycode, t_data *vars)
{
	printf("%d\n", keycode);
	if (keycode == 2)
	{
		x1 = 100;
		y1 = 100;
	}
}

int	put_pixel(t_data *data)
{
	int	x = x1-50;
	int	y = y1-50;
	char	*dst;
	    while (y <= y1)
    {
        dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	    *(unsigned int*)dst = 0x00FF0000;
		if (x == x1)
		{
			y++;
			x = -1;
		}
        x++;
    }
	mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
}

int	render_next_frame(int keycode, t_data *data)
{
	int	x = 0;
	int y = 0;
	printf ("%d\n", keycode);
	if (keycode == 2)
	{
		x += 50;
		y += 50;
	}
    mlx_put_image_to_window(mlx, mlx_win, data->img, x, y);
}

int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	t_data	img;
    int i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 50, 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	put_pixel(&img);
	// mlx_loop_hook(mlx, render_next_frame, &img);
	mlx_key_hook(mlx_win, render_next_frame, &img);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}