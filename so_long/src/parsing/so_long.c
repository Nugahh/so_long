/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:50:27 by fwong             #+#    #+#             */
/*   Updated: 2022/09/19 18:30:14 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc == 2)
	{
		printf("CACA\n");
		ft_init_struct(&data);
		get_map(&data, argv[1]);
		ft_copy_map(&data);
		printf("CACA\n");
		for (int i = 0; data.map_fill[i]; i++)
			printf("%s", data.map_fill[i]);
		ft_check_path(&data);
		// if (ft_check_map(&data, argv[1]) && ft_check_path(&data))
		// {
		// 	printf("CACA\n");
		// 	start_game(&data);
		// }
	}
	return (0);
}