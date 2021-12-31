#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int	g_time = 0;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


int	first(int keycode, t_vars *vars)
{
	if (g_time == 0)
		write (1, "didnt work", 10);
	else
		write (1, "work", 4);
}
int	second(int keycode, t_vars *vars)
{
	// mlx_hook(vars->win, 3, 1L<<1, first, &vars);
	// sleep(2);
	// g_time = 1;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, second, &vars);
	mlx_loop(vars.mlx);
}