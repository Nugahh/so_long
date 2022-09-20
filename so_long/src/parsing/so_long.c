/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:50:27 by fwong             #+#    #+#             */
/*   Updated: 2022/09/20 23:36:25 by fwong            ###   ########.fr       */
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
		if (!get_map(&data, argv[1]))
			return (ft_clean_before_exit(&data), 1);
		if (ft_check_map(&data, argv[1]) && ft_check_path(&data))
			start_game(&data);
		else
			ft_clean_before_exit(&data);
		ft_clean_before_exit(&data);
	}
	return (0);
}