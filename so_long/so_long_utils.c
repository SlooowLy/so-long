#include "lib.h"

void    give_null_value(t_data *data)
{
	data->mapinfo.collnumber = 0;
	data->mapinfo.doornumber = 0;
	data->mapinfo.collgot = 0;
}

void    allocating(t_data *data)
{
    data->mapinfo.walls = malloc ((data->mapinfo.wallsnumber+1) * sizeof (int));
	data->mapinfo.coll = malloc ((data->mapinfo.collnumber+1) * sizeof (int));
	data->mapinfo.door = malloc ((data->mapinfo.doornumber+1) * sizeof (int));
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}