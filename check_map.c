#include "lib.h"

int check_map(char *map)
{
	int		i;
	int		j;
	char	**map_c;

	map_c = ft_split(map, '_');
	while (map_c[i])
	{
		while (map_c[i][j])
		{
			write (1, &map_c[i][j], 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int main()
{
	char *n = "aaitouali_aaitouali";
	check_map(n);

}