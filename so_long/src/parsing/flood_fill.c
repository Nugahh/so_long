/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:13:39 by fwong             #+#    #+#             */
/*   Updated: 2022/09/10 03:44:29 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_player(t_data *data, t_utils *utils)
{
	int		i;
	int		j;

	i = 0;
	while (utils->map_fill[i])
	{
		j = 0;
		while (utils->map_fill[i][j])
		{
			if (utils->map_fill[i][j] == 'P' &&
			(utils->map_fill[i][j + 1] == 'C'
			|| utils->map_fill[i][j + 1] == '0'
			|| utils->map_fill[i - 1][j] == 'C'
			|| utils->map_fill[i - 1][j] == '0'
			|| utils->map_fill[i][j - 1] == 'C'
			|| utils->map_fill[i][j - 1] == '0'
			|| utils->map_fill[i + 1][j] == 'C'
			|| utils->map_fill[i + 1][j] == '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_change_to_player(t_data *data, t_utils *utils, int i, int j)
{
	if (utils->map_fill[i][j + 1] == '0' || utils->map_fill[i][j + 1] == 'C')
	{
		utils->map_fill[i][j + 1] = 'P';
		if (utils->map_fill[i][j + 1] == 'C')
			utils->count_collectible++;
	}
	if (utils->map_fill[i - 1][j] == '0' || utils->map_fill[i - 1][j] == 'C')
	{
		utils->map_fill[i - 1][j] = 'P';
		if (utils->map_fill[i - 1][j] == 'C')
			utils->count_collectible++;
	}
	if (utils->map_fill[i][j - 1] == '0' || utils->map_fill[i][j - 1] == 'C')
	{
		utils->map_fill[i][j - 1] = 'P';
		if (utils->map_fill[i][j - 1] == 'C')
			utils->count_collectible++;
	}
	if (utils->map_fill[i + 1][j] == '0' || utils->map_fill[i + 1][j] == 'C')
	{
		utils->map_fill[i + 1][j] = 'P';
		if (utils->map_fill[i + 1][j] == 'C')
			utils->count_collectible++;
	}
	utils->tab[utils->map_fill[i][j]] = 1;
}

int	ft_check_exit(t_data *data, t_utils *utils, int i, int j)
{
	if (utils->map_fill[i][j + 1] == 'E'
		|| utils->map_fill[i - 1][j] == 'E'
		|| utils->map_fill[i][j] - 1 == 'E'
		|| utils->map_fill[i + 1][j] == 'E')
		utils->exit = true;
}

void	ft_flood_fill(t_data *data, t_utils *utils)
{
	int		i;
	int		j;

	i = 0;
	while (utils->map_fill[i])
	{
		j = 0;
		while (utils->map_fill[i][j])
		{
			if (ft_check_player(data, utils)
				&& utils->tab[(int)utils->map_fill[i][j]] != 1)
			{
				ft_change_to_player(data, utils, i, j);
				i--;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_path(t_data *data, t_utils *utils)
{
	ft_flood_fill(data, utils);
	if (utils->count_collectible == utils->total_collectible
		&& utils->exit == true)
		return (1);
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
