/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:43:56 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 19:43:58 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

int	ft_exit(t_data *data)
{
	if (data->message == 1)
		write (1, "Rammus sending his greeting\n", 29);
	if (data->message == 2)
		write (1, "U WON\n", 7);
	if (data->message == 3)
		write (1, "Arg error\n", 11);
	if (data->message != 3)
	{
		free (data->map_d);
		ft_free(data->map);
	}
	exit(0);
	return (0);
}
