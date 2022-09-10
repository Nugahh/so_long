/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:16:10 by fwong             #+#    #+#             */
/*   Updated: 2022/09/10 03:34:14 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_rectangle_map(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\0' && i == 0)
				k = j;
			else if (data->map[i][j] == '\0' && k != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_wall(t_data *data, char *argv)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ft_count_line(argv))
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == '\n')
				data->map[i][j] = '\0';
		if (data->map[i][0] != '1' || data->map[i][j - 2] != '1')
			return (0);
	}
	j = -1;
	while (data->map[0][++j])
		if (data->map[0][j] != '1')
			return (0);
	j = -1;
	while (data->map[ft_count_line(argv) - 1][++j])
		if (data->map[ft_count_line(argv) - 1][j] != '1')
			return (0);
	return (1);
}

int	ft_check_each(t_data *data)
{
	int		i;
	int		j;
	bool	player;
	bool	collectible;
	bool	exit;

	i = 0;
	while (data->map[i])
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
