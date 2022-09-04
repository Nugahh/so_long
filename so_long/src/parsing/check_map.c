/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:16:10 by fwong             #+#    #+#             */
/*   Updated: 2022/09/04 21:19:48 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdbool.h>

/* int	check_rectangle_map(t_data *data, char *argv)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_count_line(argv);
	if (ft_strlen(data->map[0]) == ft_strlen(data->map[line_len - 1]))
		return (1);
	return (0);
} */

int	check_rectangle_map(t_data *data, char *argv)
{
	t_utils	*utils;
	int	i;

	i = 0;
	while (i < utils->nb_line)
	{
		if (utils->line_len[i] != utils->line_len[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_data *data, char *argv)
{
	t_utils	*utils;
	int		i;
	int		j;

	i = 1;
	while (i < utils->nb_line - 1)
	{
		j = -1;
		while (data->map[0][++j])
			if (data->map[0][j] != '1')
				return (0);
		j = -1;
		while (data->map[utils->nb_line - 1][++j])
			if (data->map[utils->nb_line - 1][j] != '1')
				return (0);
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][0] != '1'
			|| data->map[i][utils->line_len[i] - 1] != '1')
				return (0);
	}
}

int	check_each(t_data *data, char *argv)
{
	int		i;
	int		j;
	bool	player;
	bool	collectible;
	bool	exit;

	i = 0;
	while (data->map[i][j])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				player = true;
			else if (data->map[i][j] == 'C')
				collectible = true;
			else if (data->map[i][j] == 'E')
				exit = true;
			j++;
		}
		i++;
	}
	if (player == true && collectible == true && exit == true)
		return (1);
	return (0);
}

