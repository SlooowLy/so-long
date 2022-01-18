/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:49:19 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 19:49:48 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	tol(long n)
{
	long	i;
	long	k;

	i = 0;
	k = 0;
	if (n < 0)
	{
		k = 1;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1 + k);
}

void	emer(char *A, int k, long n)
{
	int	i;

	i = k;
	while (k-- >= 0)
	{
		A[i--] = '0' + (n % 10);
		n = n / 10;
	}
}

int	ft_itoa(int j, t_data *m)
{
	char	*a_f;
	int		k;
	int		n;

	n = j;
	k = tol(n);
	a_f = malloc(k + 1);
	if (a_f == 0)
		return (0);
	a_f[k--] = '\0';
	emer(a_f, k, n);
	mlx_string_put(m->ml, m->wi, 0, 0, 0XFF0000, a_f);
	free (a_f);
	return (1);
}

void	give_value(t_data *data)
{
	data->mapinfo.collgot = 0;
	data->message = 0;
	data->mapinfo.collnumber = 0;
	data->numberofmovements = 0;
	data->player_eve = 1;
	// data->mapinfo.ennumber = 0;
	data->i = len(data->map[0]);
	data->j = check_len(data->map);
}

void	map_message(t_data *data)
{
	if (!check_map(data->map, data->map_d))
		map_error(data);
	if (!(len(data->map_d)))
		map_error(data);
}
