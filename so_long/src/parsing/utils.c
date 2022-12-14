/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:39:46 by fwong             #+#    #+#             */
/*   Updated: 2022/09/24 15:47:46 by fwong            ###   ########.fr       */
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
	if (map == NULL)
		return (close(fd), free(map), ft_error(data), exit(0), 0);
	if (!map)
		return (close(fd), exit(0), 0);
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

int	ft_remove_nl(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\n' || data->map[i][j] == '\r')
				data->map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_ber_ext(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e'
		&& argv[i - 3] == 'b' && argv[i - 4] == '.')
		return (1);
	return (ft_putstr_fd("Error\nFile should be .ber extension!\n", 1), 0);
}

void	ft_error(t_data *data)
{
	if (!data->map || data->map == NULL)
		ft_putstr_fd("Error\nMap doesn't exist!\n", 1);
	else if (!data->map_fill)
		ft_putstr_fd("Error\nMap_fill doesn't exist!\n", 1);
	else if (!ft_check_rectangle_map(data))
		ft_putstr_fd("Error\nMap should be rectangle\n", 1);
	else if (!ft_check_wall(data))
		ft_putstr_fd("Error\nWalls should be filled with '1'\n", 1);
	else if (!ft_check_each(data))
		ft_putstr_fd("Error\nThere should be at least 1 P, 1 C and 1 E\n", 1);
	else if (!ft_check_map(data))
		ft_putstr_fd("Error\nUnauthorized characters in the map\n", 1);
	else if (!ft_check_exit(data))
		ft_putstr_fd("Error\nExit not reachable by the Player!\n", 1);
}

void	ft_init_struct(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->p_img = NULL;
	data->w_img = NULL;
	data->c_img = NULL;
	data->f_img = NULL;
	data->ec_img = NULL;
	data->eo_img = NULL;
	data->map = NULL;
	data->map_fill = NULL;
	data->height = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->exit = 0;
	data->step_count = 0;
	data->count_c = 0;
	data->count_e = 0;
	data->count_p = 0;
	data->total_c = 0;
}
