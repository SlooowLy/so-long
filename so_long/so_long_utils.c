#include "lib.h"

void    give_null_value(t_data *data)
{
    data->mapinfo.wallsnumber = 0;
	data->mapinfo.collnumber = 0;
	data->mapinfo.doornumber = 0;
	data->mapinfo.collgot = 0;
}

void    allocating(t_data *data)
{
    data->mapinfo.walls = malloc (data->mapinfo.wallsnumber+1);
	data->mapinfo.coll = malloc (data->mapinfo.collnumber+1);
	data->mapinfo.door = malloc (data->mapinfo.doornumber+1);
}
