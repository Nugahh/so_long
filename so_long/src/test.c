/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:05:30 by fwong             #+#    #+#             */
/*   Updated: 2022/08/26 01:05:30 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

#define MLX_ERROR 1

int	init_ptr(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, 500, 800, "My first window!");
	if (data->win == NULL)
		return (free(data->win), MLX_ERROR);
	while (1);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
