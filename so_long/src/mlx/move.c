/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:34 by fwong             #+#    #+#             */
/*   Updated: 2022/09/25 19:03:20 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_move_up(t_data *data)
{
	if (data->map[data->y - 1][data->x] == 'E' && data->exit == 1)
		mlx_loop_end(data->mlx);
	if ((data->map[data->y - 1][data->x] != '1'
		&& data->map[data->y - 1][data->x] != 'E'))
	{
		if (data->map[data->y - 1][data->x] == 'C')
			data->count_c++;
		data->map[data->y - 1][data->x] = 'P';
		data->map[data->y][data->x] = '0';
		data->y--;
		data->step_count++;
	}
	if (data->count_c == data->total_c)
		data->exit = 1;
}

void	ft_move_down(t_data *data)
{
	if (data->map[data->y + 1][data->x] == 'E' && data->exit == 1)
		mlx_loop_end(data->mlx);
	if (data->map[data->y + 1][data->x] != '1'
		&& data->map[data->y + 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'C')
			data->count_c++;
		data->map[data->y + 1][data->x] = 'P';
		data->map[data->y][data->x] = '0';
		data->y++;
		data->step_count++;
	}
	if (data->count_c == data->total_c)
		data->exit = 1;
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->y][data->x - 1] == 'E' && data->exit == 1)
		mlx_loop_end(data->mlx);
	if (data->map[data->y][data->x - 1] != '1'
		&& data->map[data->y][data->x - 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'C')
			data->count_c++;
		data->map[data->y][data->x - 1] = 'P';
		data->map[data->y][data->x] = '0';
		data->x--;
		data->step_count++;
	}
	if (data->count_c == data->total_c)
		data->exit = 1;
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->y][data->x + 1] == 'E' && data->exit == 1)
		mlx_loop_end(data->mlx);
	if (data->map[data->y][data->x + 1] != '1'
		&& data->map[data->y][data->x + 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'C')
			data->count_c++;
		data->map[data->y][data->x + 1] = 'P';
		data->map[data->y][data->x] = '0';
		data->x++;
		data->step_count++;
	}
	if (data->count_c == data->total_c)
		data->exit = 1;
}

int	ft_move(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx);
	if (keycode == XK_w || keycode == XK_Up)
		ft_move_up(data);
	else if (keycode == XK_s || keycode == XK_Down)
		ft_move_down(data);
	else if (keycode == XK_a || keycode == XK_Left)
		ft_move_left(data);
	else if (keycode == XK_d || keycode == XK_Right)
		ft_move_right(data);
	return (0);
}
