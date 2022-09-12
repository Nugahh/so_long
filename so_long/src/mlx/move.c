/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:34 by fwong             #+#    #+#             */
/*   Updated: 2022/09/12 22:51:42 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_find_player(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				return(data->y = i, data->x = j);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_move_up(t_data *data, t_utils *utils)
{
	if (data->map[data->y - 1][data->x] != '1' && utils->exit == false)
	{
		data->map[data->y][data->x + 1] = 'P';
		data->map[data->y][data->x + 1] = '0';
		data->y -= 1;
	}
	else if (data->map[data->y - 1][data->x] == 'E' && utils->exit == true)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map[data->y - 1][data->x] == 'C')
		utils->count_collectible++;
}

void	ft_move_down(t_data *data, t_utils *utils)
{
	if (data->map[data->y + 1][data->x] != '1' && utils->exit == false)
	{
		data->map[data->y + 1][data->x] = 'P';
		data->map[data->y + 1][data->x] = '0';
		data->x += 1;
	}
	else if (data->map[data->y + 1][data->x] == 'E' && utils->exit == true)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map[data->y + 1][data->x] == 'C')
		utils->count_collectible++;
}

void	ft_move_left(t_data *data, t_utils *utils)
{
	if (data->map[data->y][data->x - 1] != '1' && utils->exit == false)
	{
		data->map[data->y][data->x - 1] = 'P';
		data->map[data->y][data->x - 1] = '0';
		data->x -= 1;
	}
	else if (data->map[data->y][data->x - 1] == 'E' && utils->exit == true)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map[data->y][data->x - 1] == 'C')
		utils->count_collectible++;
}

void	ft_move_right(t_data *data, t_utils *utils)
{
	if (data->map[data->y][data->x + 1] != '1' && utils->exit == false)
	{
		data->map[data->y][data->x + 1] = 'P';
		data->map[data->y][data->x + 1] = '0';
		data->x += 1;
	}
	else if (data->map[data->y][data->x + 1] == 'E' && utils->exit == true)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map[data->y][data->x + 1] == 'C')
		utils->count_collectible++;
}

int	ft_move(t_data *data, t_utils *utils, int keycode)
{
	if (keycode == XK_w || keycode == XK_Up)
		ft_move_up(data, utils);
	if (keycode == XK_s || keycode == XK_Down)
		ft_move_down(data, utils);
	if (keycode == XK_a || keycode == XK_Left)
		ft_move_left(data, utils);
	if (keycode == XK_d || keycode == XK_Right)
		ft_move_right(data, utils);
	return (0);
}