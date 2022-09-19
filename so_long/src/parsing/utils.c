/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:39:46 by fwong             #+#    #+#             */
/*   Updated: 2022/09/19 18:22:00 by fwong            ###   ########.fr       */
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
	if (!map)
		return (close(fd), 1);
	int x = 0;
	while (map)
	{
		ft_putnbr_fd(x, 1);
		free(map);
		map = get_next_line(fd);
		count++;
		x++;
	}
	close(fd);
	data->height = count;
	return (count);
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
	data->count_C = 0;
	data->count_E = 0;
	data->count_P = 0;
	data->total_C = 0;
}
