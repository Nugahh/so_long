/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:39:46 by fwong             #+#    #+#             */
/*   Updated: 2022/09/17 19:12:09 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_count_line(char *argv, t_data *data)
{
	int		count;
	int		fd;
	char	*map;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (0);
	map = get_next_line(fd);
	while (map)
	{
		free(map);
		map = get_next_line(fd);
		count++;
	}
	close(fd);
	data->height = count;
	return (count);
}

int	ft_count_collectible(t_data *data)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = -1;
	p = 0;
	e = 0;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->total_collectible++;
			if (data->map[i][j] == 'P')
				p++;
			if (data->map[i][j] == 'E')
				e++;
			j++;
		}
	}
	if (p != 1 || e != 1)
		return (0);
	return (1);
}

void	ft_init_struct(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->P_IMG = NULL;
	data->W_IMG = NULL;
	data->C_IMG = NULL;
	data->F_IMG = NULL;
	data->EC_IMG = NULL;
	data->EO_IMG = NULL;
	data->map = NULL;
	data->map_fill = NULL;
	data->height = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->count_collectible = 0;
	data->total_collectible = 0;
}
