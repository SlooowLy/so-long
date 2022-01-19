/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:43:13 by aaitoual          #+#    #+#             */
/*   Updated: 2022/01/15 19:43:14 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	int		j;
	char	*a1;

	i = len(s1) + len(s2);
	j = 0;
	k = 0;
	a1 = malloc(i + 1);
	if (a1 == 0)
		return (0);
	while (s1 && s1[j] != '\0')
	{
		a1[j] = s1[j];
		j++;
	}
	while (s2 && s2[k] != '\0')
		a1[j++] = s2[k++];
	a1[j] = '\0';
	return (a1);
}

int	read_map(char **all, int fd)
{
	char	*curr;
	int		i;
	int		j;

	i = 0;
	j = 1;
	curr = malloc(1 + 1);
	*all = NULL;
	while (i == 0 && j != 0)
	{
		j = read(fd, curr, 1);
		if (curr[0] != 'P' && curr[0] != 'E' && curr[0] != 'C'
			&& curr[0] != '0' && curr[0] != '1' && curr[0] != 'X')
			return (2);
		if (j == -1)
			break ;
		if (j == 0)
			break ;
		curr[j] = '\0';
		*all = ft_strjoin(*all, curr);
	}
	if (j != -1)
		free (curr);
	return (1);
}

int	get_r(void)
{
	return ((rand() % 4) + 1);
}

void	change_player_next_position(t_data *data, int j, int k, int r)
{
	if (r == 1)
		data->map[j][k + 1] = 'X';
	if (r == 2)
		data->map[j][k - 1] = 'X';
	if (r == 3)
		data->map[j + 1][k] = 'X';
	if (r == 4)
		data->map[j - 1][k] = 'X';
}

char	f_u_25line(t_data *m, int r, int j, int k)
{
	if (r == 1)
		return (m->map[j][k + 1]);
	if (r == 2)
		return (m->map[j][k - 1]);
	if (r == 3)
		return (m->map[j + 1][k]);
	if (r == 4)
		return (m->map[j - 1][k]);
	return (0);
}
