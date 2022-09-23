/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:23:41 by fwong             #+#    #+#             */
/*   Updated: 2022/09/23 15:22:10 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_map(t_data *data, char *argv)
{
	int i;
	int fd;
	int size;

	size = ft_count_line(argv, data);
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (ft_putstr_fd("Error\nfd is not correct!\n", 1), 0);
	data->map = malloc(sizeof(char *) * (size + 1));
	if (!data->map)
		return (0);
	i = 0;
	while (i < size + 1)
		data->map[i++] = get_next_line(fd);
	close(fd);
	ft_remove_nl(data);
	data->width = ft_strlen(data->map[0]);
	ft_copy_map(data);
	return (1);
}

int ft_copy_map(t_data *data)
{
	int i;
	int j;
	int len;

	data->map_fill = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map_fill)
		return (ft_error(data), 0);
	i = 0;
	while (i < data->height)
	{
		len = ft_strlen(data->map[i]);
		data->map_fill[i] = malloc(sizeof(char) * (len + 1));
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

// int	main(int argc, char **argv)
// {
// 	t_data	data;
// 	t_utils	utils;

// 	if (argc == 2)
// 	{
// 	get_map(&data, &utils, argv[1]);
// 	// ft_check_path(&utils);
// 	printf("check path %d\n", ft_check_path(&data, &utils));
// 	printf("check_map %d\n", ft_check_map(&data, argv[1]));
// 	for (int i = 0; data.map[i]; i++)
// 		printf("%s", data.map[i]);
// 	printf("\n --------------- \n");
// 	for (int i = 0; utils.map_fill[i]; i++)
// 		printf("%s", utils.map_fill[i]);
// 	}
// 	// ft_check_rectangle_map(&data, argv);
// 	// printf("Check rectangle is: %d\n", ft_check_rectangle_map(&data, argv[1]));
// 	// printf("Check each: %d\n", ft_check_each(&data, argv[1]));
// 	// printf("Check wall: %d\n", ft_check_wall(&data, argv[1]));

// }