/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:39:46 by fwong             #+#    #+#             */
/*   Updated: 2022/09/11 20:40:51 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_count_line(char *argv)
{
	int		count;
	int		fd;
	char	*map;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (0);
	map = get_next_line(fd);
	while (map)
	{
		free(map);
		count++;
		map = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	ft_count_collectible(t_data *data, t_utils *utils)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = -1;
	p = 0;
	e = 0;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				utils->total_collectible++;
			if (data->map[i][j] == 'P')
				p++;
			if (data->map[i][j] == 'E')
				e++;
			j++;
		}
	}
	if (p != 1 || e != 1)
		return (0);
	return (1);
}

void	ft_init_var(t_utils *utils)
{
	utils->count_collectible = 0;
	utils->total_collectible = 0;
}
