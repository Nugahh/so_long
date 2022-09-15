/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:22:04 by fwong             #+#    #+#             */
/*   Updated: 2022/09/15 17:07:32 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	init_ptr(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width * 64, data->height * 64, "so_long");
	if (data->win == NULL)
		return (free(data->win), 0);
	return (0);
}

void	init_img(t_data *data)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	data->P_IMG = mlx_xpm_file_to_image(data->mlx, "xpm/player.xpm", &x, &y);
	data->C_IMG = mlx_xpm_file_to_image(data->mlx, "xpm/collectible.xpm", &x, &y);
	data->W_IMG = mlx_xpm_file_to_image(data->mlx, "xpm/wall.xpm", &x, &y);
	data->F_IMG = mlx_xpm_file_to_image(data->mlx, "xpm/floor.xpm", &x, &y);
	data->EC_IMG = mlx_xpm_file_to_image(data->mlx, "xpm/ec.xpm", &x, &y);
	data->EO_IMG = mlx_xpm_file_to_image(data->mlx, "xpm/eo.xpm", &x, &y);
}

int	ft_display_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->P_IMG, y * 64, x * 64);
			else if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->C_IMG, y * 64, x * 64);
			else if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->W_IMG, y * 64, x * 64);
			else if (data->map[x][y] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->F_IMG, y * 64, x * 64);
			else if (data->map[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->EC_IMG, y * 64, x * 64);
			y++;
		}
		x++;
	}
	return (0);
}

int	main (int argc, char **argv)
{
	t_data data;
	
	if (argc == 2)
	{
		ft_init_struct(&data);
		get_map(&data, argv[1]);
		init_ptr(&data);
		init_img(&data);
		// ft_display_map(&data);
		ft_find_player(&data);
		mlx_loop_hook(data.mlx, ft_display_map, &data);
		printf("data->exit = %d", data.exit);
		printf("data->count = %d", data.count_collectible);
		printf("data->total = %d", data.total_collectible);
		mlx_hook(data.win, 2, 1L<<0, ft_move, &data);
		//mlx_key_hook(data.win, ft_move, &data);
		mlx_loop(data.mlx);
	}
}