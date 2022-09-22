/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:34 by fwong             #+#    #+#             */
/*   Updated: 2022/09/21 23:16:38 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_find_player(t_data *data)
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
			{
				data->y = i;
				data->x = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_move_up(t_data *data)
{
	if (data->map[data->y - 1][data->x] == 'E' && data->exit == 1)
		mlx_loop_end(data->mlx);	
	if ((data->map[data->y - 1][data->x] != '1' 
		&& data->map[data->y - 1][data->x] != 'E'))
	{
		if (data->map[data->y - 1][data->x] == 'C')
			data->count_C++;
		data->map[data->y - 1][data->x] = 'P';
		data->map[data->y][data->x] = '0';
		data->y--;
	}
	if (data->count_C == data->total_C)
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
			data->count_C++;
		data->map[data->y + 1][data->x] = 'P';
		data->map[data->y][data->x] = '0';
		data->y++;
	}
	if (data->count_C == data->total_C)
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
			data->count_C++;
		data->map[data->y][data->x - 1] = 'P';
		data->map[data->y][data->x] = '0';
		data->x--;
	}
	if (data->count_C == data->total_C)
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
			data->count_C++;
		data->map[data->y][data->x + 1] = 'P';
		data->map[data->y][data->x] = '0';
		data->x++;
	}
	if (data->count_C == data->total_C)
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
