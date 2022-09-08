/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:23:41 by fwong             #+#    #+#             */
/*   Updated: 2022/09/08 21:34:50 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_map(t_data *data, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	data->map = malloc(sizeof(char *) * (ft_count_line(argv) + 1));
	if (!data->map)
		return ;
	data->map_fill = malloc(sizeof(char *) * (ft_count_line(argv) + 1));
	if (!data->map_fill)
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
		data->map_fill = get_next_line(fd);
	} 
	close(fd);
}

int	main (int argc, char **argv)
{
	t_data	data;

	get_map(&data, argv[1]);
	
	
	for (int i = 0; data.map[i]; i++)
		printf("%s", data.map[i]);

	// ft_check_rectangle_map(&data, argv);
	// printf("Check rectangle is: %d\n", ft_check_rectangle_map(&data, argv[1]));
	// printf("Check each: %d\n", ft_check_each(&data, argv[1]));
	// printf("Check wall: %d\n", ft_check_wall(&data, argv[1]));

}