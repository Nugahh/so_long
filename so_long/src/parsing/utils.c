/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:39:46 by fwong             #+#    #+#             */
/*   Updated: 2022/09/04 23:01:23 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_count_line(char *argv)
{

	int	count = 0;
	int	fd = 0;
	char *map;
	
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return 0;
	map = get_next_line(fd);
	while (map) 
	{
		free(map);
		count++;
		map = get_next_line(fd);
	} 
	close(fd);
	return (count++);
}
