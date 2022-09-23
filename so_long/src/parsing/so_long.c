/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:50:27 by fwong             #+#    #+#             */
/*   Updated: 2022/09/23 13:17:50 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		ft_init_struct(&data);
		if (!ft_check_ber_ext(argv[1]))
			return (0);
		if (!get_map(&data, argv[1]))
			return (ft_clean_before_exit(&data), 0);
		if (ft_check_map(&data) && ft_check_path(&data))
			start_game(&data);
		ft_clean_before_exit(&data);
	}
	return (1);
}