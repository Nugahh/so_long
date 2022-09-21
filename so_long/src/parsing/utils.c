/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:39:46 by fwong             #+#    #+#             */
/*   Updated: 2022/09/21 06:53:43 by fwong            ###   ########.fr       */
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

void	ft_error(t_data *data)
{
	if (!ft_check_rectangle_map(data))
		ft_putstr_fd("Error\nMap should be rectangle\n", 1);
	if (!ft_check_wall(data))
		ft_putstr_fd("Error\nWalls should be filled with '1'\n", 1);
	if (!ft_check_each(data))
		ft_putstr_fd("Error\nThere should be at least 1 P, 1 C and 1 E\n", 1);
	if (!ft_check_map(data))
		ft_putstr_fd("Error\nUnauthorized characters in the map\n", 1);
	if
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
	data->exit = 0;
	data->count_C = 0;
	data->count_E = 0;
	data->count_P = 0;
	data->total_C = 0;
}
