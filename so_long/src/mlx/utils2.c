/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:29:45 by fwong             #+#    #+#             */
/*   Updated: 2022/09/19 16:36:11 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
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
	while (data->map_fill[i])
	{
		free(data->map_fill[i]);
		i++;
	}
	free(data->map_fill);
}

int	ft_clean_before_exit(t_data *data)
{
	ft_free_map(data);
	ft_free_map_fill(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->C_IMG);
	mlx_destroy_image(data->mlx, data->EC_IMG);
	mlx_destroy_image(data->mlx, data->EO_IMG);
	mlx_destroy_image(data->mlx, data->W_IMG);
	mlx_destroy_image(data->mlx, data->P_IMG);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
