#include "lib.h"

int ft_exit(t_data *data)
{
	if (data->message == 1)
		write (1, "Rammus sending his greeting\n", 29);
	free (data->map_d);
	ft_free(data->map);
	exit(0);
	return (0);
}