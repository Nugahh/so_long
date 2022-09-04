/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:23:41 by fwong             #+#    #+#             */
/*   Updated: 2022/09/04 14:27:14 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_count_line(char *argv)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

void	get_map(t_data *data, char *argv)
{
	int		i;
	int		fd;
	int		size;
	char	*line;

	i = 1;
	fd = open(argv, O_RDONLY);
	size = ft_count_line(argv);
	data->map = malloc(sizeof(char *) * (size + 1));
	line = get_next_line(fd);
	data->map[0] = malloc(sizeof(char) * ft_strlen(line) + 1);
	data->map[0] = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->map[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		data->map[i] = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	close(fd);
}

int	main (int argc, char **argv)
{
	t_data *data;

	get_map(data, argv[1]);
}