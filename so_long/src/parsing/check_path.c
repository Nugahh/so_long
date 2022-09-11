/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:13:39 by fwong             #+#    #+#             */
/*   Updated: 2022/09/11 19:55:57 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_player(t_utils *utils, int i, int j)
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
	return (0);
}

void	ft_change_to_player(t_utils *utils, int i, int j)
{
	if (utils->map_fill[i][j + 1] == '0' || utils->map_fill[i][j + 1] == 'C')
	{
		if (utils->map_fill[i][j + 1] == 'C')
			utils->count_collectible++;
		utils->map_fill[i][j + 1] = 'P';
	}
	if (utils->map_fill[i - 1][j] == '0' || utils->map_fill[i - 1][j] == 'C')
	{
		if (utils->map_fill[i - 1][j] == 'C')
			utils->count_collectible++;
		utils->map_fill[i - 1][j] = 'P';
	}
	if (utils->map_fill[i][j - 1] == '0' || utils->map_fill[i][j - 1] == 'C')
	{
		if (utils->map_fill[i][j - 1] == 'C')
			utils->count_collectible++;
		utils->map_fill[i][j - 1] = 'P';
	}
	if (utils->map_fill[i + 1][j] == '0' || utils->map_fill[i + 1][j] == 'C')
	{
		if (utils->map_fill[i + 1][j] == 'C')
			utils->count_collectible++;
		utils->map_fill[i + 1][j] = 'P';
	}
	utils->tab[(int)utils->map_fill[i][j]] = 1;
}

void	ft_check_exit(t_utils *utils)
{
	int	i;
	int	j;

	i = 0;
	while (utils->map_fill[i])
	{
		j = 0;
		while (utils->map_fill[i][j])
		{
			if (utils->map_fill[i][j] == 'E')
			{
				if (utils->map_fill[i][j + 1] == 'P'
					|| utils->map_fill[i - 1][j] == 'P'
					|| utils->map_fill[i][j - 1] == 'P'
					|| utils->map_fill[i + 1][j] == 'P')
					utils->exit = true;
				printf("bool = %d\n", utils->exit);
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_utils *utils)
{
	int		i;
	int		j;

	i = 0;
	while (utils->map_fill[i])
	{
		j = 0;
		while (utils->map_fill[i][j])
		{
			if (ft_check_player(utils, i, j))
			{
				ft_change_to_player(utils, i, j);
				i = 0;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_path(t_data *data, t_utils *utils)
{
	ft_init_var(utils);
	ft_flood_fill(utils);
	ft_check_exit(utils);
	if (ft_count_collectible(data, utils))
	{
		if (utils->count_collectible == utils->total_collectible
			&& utils->exit == true)
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
