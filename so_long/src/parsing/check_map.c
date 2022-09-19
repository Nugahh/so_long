/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:16:10 by fwong             #+#    #+#             */
/*   Updated: 2022/09/19 18:22:13 by fwong            ###   ########.fr       */
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
	while (++i < ft_count_line(argv, data))
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
	while (data->map[ft_count_line(argv, data) - 1][++j])
		if (data->map[ft_count_line(argv, data) - 1][j] != '1')
			return (0);
	return (1);
}

int	ft_check_each(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->count_P++;
			else if (data->map[i][j] == 'C')
				data->total_C++;
			else if (data->map[i][j] == 'E')
				data->count_E++;
			j++;
		}
		i++;
	}
	if (data->count_P == 1 && data->total_C >= 1 && data->count_E == 1)
		return (1);
	return (0);
}

int	ft_check_map(t_data *data, char *argv)
{
	int	i;
	int	j;
	
	if (!ft_check_rectangle_map(data))
		return (0);
	if (!ft_check_wall(data, argv))
		return (0);
	if (!ft_check_each(data))
		return (0);
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] && 
			(data->map[i][j] != 'P'
			&& data->map[i][j] != 'E'
			&& data->map[i][j] != '0'
			&& data->map[i][j] != '1'
			&& data->map[i][j] != 'C'))
				return (0);
		}	
	}
	return (1);
}