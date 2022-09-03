/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:23:41 by fwong             #+#    #+#             */
/*   Updated: 2022/09/03 21:48:32 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_map(t_data *data)
{
	int	i;
	int	fd;
	char	*line;

	i = 1;
	data->map = malloc(sizeof(char *) * 10000);
	fd = open("../maps/test.ber", O_RDONLY);
	line = get_next_line(fd);
	data->map[0] = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		free(line);
		data->map[i] = malloc(sizeof(char) * 1000);
		line = get_next_line(fd);
		data->map[i] = get_next_line(fd);
		printf("%s", line);
		i++;
	}
}

int	main (void)
{
	t_data *data;

	get_map(data);
	int i = 0;
	while (i < 5)
	{
		printf("%s", data->map[i]);
		i++; 
	}
}