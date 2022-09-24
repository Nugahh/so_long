/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:23:41 by fwong             #+#    #+#             */
/*   Updated: 2022/09/24 15:44:15 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_map(t_data *data, char *argv)
{
	int	i;
	int	fd;
	int	size;

	size = ft_count_line(argv, data);
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (ft_putstr_fd("Error\nfd is not correct!\n", 1), close(fd), 0);
	data->map = ft_calloc((size + 1), (sizeof(char *)));
	if (!data->map)
		return (close(fd), 0);
	i = 0;
	while (i < size + 1)
		data->map[i++] = get_next_line(fd);
	close(fd);
	ft_remove_nl(data);
	data->width = ft_strlen(data->map[0]);
	ft_copy_map(data);
	return (1);
}

int	ft_copy_map(t_data *data)
{
	int	i;
	int	j;
	int	len;

	data->map_fill = ft_calloc((data->height + 1), (sizeof(char *)));
	if (!data->map_fill)
		return (ft_error(data), 0);
	i = 0;
	while (i < data->height)
	{
		len = ft_strlen(data->map[i]);
		data->map_fill[i] = ft_calloc((len + 1), (sizeof(char)));
		if (!data->map_fill[i])
			return (ft_putstr_fd("Error\nMap_fill[i] doesn't exist!", 1), 0);
		j = -1;
		while (data->map[i][++j])
			data->map_fill[i][j] = data->map[i][j];
		data->map_fill[i][j] = 0;
		i++;
	}
	data->map_fill[i] = 0;
	return (1);
}
