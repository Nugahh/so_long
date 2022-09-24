/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:29:45 by fwong             #+#    #+#             */
/*   Updated: 2022/09/24 15:47:10 by fwong            ###   ########.fr       */
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

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_free_map_fill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map_fill[i]);
		i++;
	}
	free(data->map_fill);
}

int	ft_clean_before_exit(t_data *data)
{
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map != NULL)
		ft_free_map(data);
	if (data->map_fill != NULL)
		ft_free_map_fill(data);
	if (data->c_img != NULL)
		mlx_destroy_image(data->mlx, data->c_img);
	if (data->ec_img != NULL)
		mlx_destroy_image(data->mlx, data->ec_img);
	if (data->eo_img != NULL)
		mlx_destroy_image(data->mlx, data->eo_img);
	if (data->w_img != NULL)
		mlx_destroy_image(data->mlx, data->w_img);
	if (data->p_img != NULL)
		mlx_destroy_image(data->mlx, data->p_img);
	if (data->f_img != NULL)
		mlx_destroy_image(data->mlx, data->f_img);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	return (0);
}

int	ft_clean_before_exit2(t_data *data)
{
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map != NULL)
		ft_free_map(data);
	if (data->map_fill != NULL)
		ft_free_map_fill(data);
	if (data->c_img != NULL)
		mlx_destroy_image(data->mlx, data->c_img);
	if (data->ec_img != NULL)
		mlx_destroy_image(data->mlx, data->ec_img);
	if (data->eo_img != NULL)
		mlx_destroy_image(data->mlx, data->eo_img);
	if (data->w_img != NULL)
		mlx_destroy_image(data->mlx, data->w_img);
	if (data->p_img != NULL)
		mlx_destroy_image(data->mlx, data->p_img);
	if (data->f_img != NULL)
		mlx_destroy_image(data->mlx, data->f_img);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
