/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:29:45 by fwong             #+#    #+#             */
/*   Updated: 2022/09/21 23:38:03 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	if (data->C_IMG != NULL)
		mlx_destroy_image(data->mlx, data->C_IMG);
	if (data->EC_IMG != NULL)
		mlx_destroy_image(data->mlx, data->EC_IMG);
	if (data->EO_IMG != NULL)
		mlx_destroy_image(data->mlx, data->EO_IMG);
	if (data->W_IMG != NULL)
		mlx_destroy_image(data->mlx, data->W_IMG);
	if (data->P_IMG != NULL)
		mlx_destroy_image(data->mlx, data->P_IMG);
	if (data->F_IMG != NULL)
		mlx_destroy_image(data->mlx, data->F_IMG);
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
	if (data->C_IMG != NULL)
		mlx_destroy_image(data->mlx, data->C_IMG);
	if (data->EC_IMG != NULL)
		mlx_destroy_image(data->mlx, data->EC_IMG);
	if (data->EO_IMG != NULL)
		mlx_destroy_image(data->mlx, data->EO_IMG);
	if (data->W_IMG != NULL)
		mlx_destroy_image(data->mlx, data->W_IMG);
	if (data->P_IMG != NULL)
		mlx_destroy_image(data->mlx, data->P_IMG);
	if (data->F_IMG != NULL)
		mlx_destroy_image(data->mlx, data->F_IMG);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
