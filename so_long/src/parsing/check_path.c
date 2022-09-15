/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:13:39 by fwong             #+#    #+#             */
/*   Updated: 2022/09/15 07:05:22 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_player(t_data *data, int i, int j)
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
	return (0);
}

void	ft_change_to_player(t_data *data, int i, int j)
{
	if (data->map_fill[i][j + 1] == '0' || data->map_fill[i][j + 1] == 'C')
	{
		if (data->map_fill[i][j + 1] == 'C')
			data->count_collectible++;
		data->map_fill[i][j + 1] = 'P';
	}
	if (data->map_fill[i - 1][j] == '0' || data->map_fill[i - 1][j] == 'C')
	{
		if (data->map_fill[i - 1][j] == 'C')
			data->count_collectible++;
		data->map_fill[i - 1][j] = 'P';
	}
	if (data->map_fill[i][j - 1] == '0' || data->map_fill[i][j - 1] == 'C')
	{
		if (data->map_fill[i][j - 1] == 'C')
			data->count_collectible++;
		data->map_fill[i][j - 1] = 'P';
	}
	if (data->map_fill[i + 1][j] == '0' || data->map_fill[i + 1][j] == 'C')
	{
		if (data->map_fill[i + 1][j] == 'C')
			data->count_collectible++;
		data->map_fill[i + 1][j] = 'P';
	}
}

void	ft_check_exit(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_fill[i])
	{
		j = 0;
		while (data->map_fill[i][j])
		{
			if (data->map_fill[i][j] == 'E')
			{
				if (data->map_fill[i][j + 1] == 'P'
					|| data->map_fill[i - 1][j] == 'P'
					|| data->map_fill[i][j - 1] == 'P'
					|| data->map_fill[i + 1][j] == 'P')
					data->exit = true;
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map_fill[i])
	{
		j = 0;
		while (data->map_fill[i][j])
		{
			if (ft_check_player(data, i, j))
			{
				ft_change_to_player(data, i, j);
				i = 0;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_path(t_data *data)
{
	ft_init_struct(data);
	ft_flood_fill(data);
	ft_check_exit(data);
	if (ft_count_collectible(data))
	{
		if (data->count_collectible == data->total_collectible
			&& data->exit == true)
			return (1);
	}
	return (0);
}

/* int	main(int argc, char **argv)
{
	t_data	data;
	t_utils	utils;

	if (argc == 2)
	{
	get_map(&data, &utils, argv[1]);
	
	for (int i = 0; data.map[i]; i++)
		printf("%s", data.map[i]);
	printf("\n");
		ft_flood_fill(&data, &utils);
	for (int i = 0; utils.map_fill[i]; i++)
		printf("%s\n", utils.map_fill[i]);
	}
} */
