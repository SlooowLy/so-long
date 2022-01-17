/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:13:31 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 20:13:33 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	tol(long n)
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

static void	emer(char *A, int k, long n)
{
	int	i;

	i = k;
	while (k-- >= 0)
	{
		A[i--] = '0' + (n % 10);
		n = n / 10;
	}
}

char	*ft_itoa(int j)
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
	return (a_f);
}

void	arg_error(t_data *data)
{
	free (data->map_d);
	ft_free(data->map);
	write (1, "Arg error\n", 11);
	exit(0);
}
