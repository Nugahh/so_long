/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:23:41 by fwong             #+#    #+#             */
/*   Updated: 2022/09/11 23:12:15 by fwong            ###   ########.fr       */
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
	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return ;
	data->map[i] = get_next_line(fd);
	if (!data->map[i])
		return ;
	while (data->map[i++])
		data->map[i] = get_next_line(fd);
	close(fd);
	// a changer sal fils de pute
	data->nb_char_per_line = ft_strlen(data->map[0]);
	data->nb_line = ft_count_line(argv);
	ft_copy_map(data, utils, argv);
}

int	ft_copy_map(t_data *data, t_utils *utils, char *argv)
{
	int	i;
	int	j;
	int	len;

	utils->map_fill = malloc(sizeof(char *) * (ft_count_line(argv) + 1));
	if (!utils->map_fill)
		return (0);
	i = -1;
	while (data->map[++i])
	{
		len = ft_strlen(data->map[i]);
		utils->map_fill[i] = malloc(sizeof(char) * (len + 1));
		if (!utils->map_fill[i])
			return (0);
		j = -1;
		while (data->map[i][++j])
			utils->map_fill[i][j] = data->map[i][j];
		utils->map_fill[i][j] = 0;
	}
	utils->map_fill[i] = 0;
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