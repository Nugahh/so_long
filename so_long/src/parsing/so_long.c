/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:50:27 by fwong             #+#    #+#             */
/*   Updated: 2022/09/19 23:13:04 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc == 2)
	{
		ft_init_struct(&data);
		get_map(&data, argv[1]);
		if (ft_check_map(&data, argv[1]) && ft_check_path(&data))
			start_game(&data);
	}
	return (0);
}