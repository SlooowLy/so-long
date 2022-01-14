#include "lib.h"

int ft_exit(t_data *data)
{
	free (data->map);
	// ft_free(&data->map_d);
	exit(0);
	return (0);
}