/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:16:10 by fwong             #+#    #+#             */
/*   Updated: 2022/09/24 15:47:46 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_rectangle_map(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (data->width != j)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == '\n')
				data->map[i][j] = '\0';
		if (data->map[i][0] != '1' || data->map[i][j - 1] != '1')
			return (0);
	}
	j = -1;
	while (data->map[0][++j])
		if (data->map[0][j] != '1')
			return (0);
	j = -1;
	while (data->map[data->height - 1][++j])
		if (data->map[data->height - 1][j] != '1')
			return (0);
	return (1);
}

int	ft_check_each(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->count_p++;
			else if (data->map[i][j] == 'C')
				data->total_c++;
			else if (data->map[i][j] == 'E')
				data->count_e++;
			j++;
		}
		i++;
	}
	if (data->count_p == 1 && data->total_c >= 1 && data->count_e == 1)
		return (1);
	return (0);
}

int	ft_check_map(t_data *data)
{
	int	i;
	int	j;

	if (!ft_check_rectangle_map(data))
		return (ft_error(data), 0);
	if (!ft_check_wall(data))
		return (ft_error(data), 0);
	if (!ft_check_each(data))
		return (ft_error(data), 0);
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] &&
			(data->map[i][j] != 'P'
			&& data->map[i][j] != 'E'
			&& data->map[i][j] != '0'
			&& data->map[i][j] != '1'
			&& data->map[i][j] != 'C'))
				return (0);
		}	
	}
	return (1);
}

int	ft_check_player_within_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_fill[i])
	{
		j = 0;
		while (data->map_fill[i][j])
		{
			if (data->map_fill[i][j] == 'P' &&
			(data->map_fill[i][j + 1] == 'C'
			|| data->map_fill[i][j + 1] == '0'
			|| data->map_fill[i - 1][j] == 'C'
			|| data->map_fill[i - 1][j] == '0'
			|| data->map_fill[i][j - 1] == 'C'
			|| data->map_fill[i][j - 1] == '0'
			|| data->map_fill[i + 1][j] == 'C'
			|| data->map_fill[i + 1][j] == '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (ft_putstr_fd("Error\nPlayer within walls!\n", 1), 0);
}
