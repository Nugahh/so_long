/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:23:41 by fwong             #+#    #+#             */
/*   Updated: 2022/09/09 22:59:07 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_map(t_data *data, t_utils *utils, char *argv)
{
	int		i;
	int		fd;

	data->map = malloc(sizeof(char *) * (ft_count_line(argv) + 1));
	if (!data->map)
		return ;
	utils->map_fill = malloc(sizeof(char *) * (ft_count_line(argv) + 1));
	if (!utils->map_fill)
		return ;
	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return ;
	data->map[i] = get_next_line(fd);
	if (!data->map[i])
		return ;
	while (data->map[i++])
	{
		data->map[i] = get_next_line(fd);
		utils->map_fill[i] = data->map[i];
	}
	close(fd);
}

// int	main(int argc, char **argv)
// {
// 	t_data	data;
// 	t_utils	utils;

// 	get_map(&data, &utils, argv[1]);
	
// 	for (int i = 0; data.map[i]; i++)
// 		printf("%s", data.map[i]);
// 	printf("\n --------------- \n");
// 	for (int i = 0; utils.map_fill[i]; i++)
// 		printf("%s", utils.map_fill[i]);

// 	// ft_check_rectangle_map(&data, argv);
// 	// printf("Check rectangle is: %d\n", ft_check_rectangle_map(&data, argv[1]));
// 	// printf("Check each: %d\n", ft_check_each(&data, argv[1]));
// 	// printf("Check wall: %d\n", ft_check_wall(&data, argv[1]));

// }