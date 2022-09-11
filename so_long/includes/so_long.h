/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:54:49 by fwong             #+#    #+#             */
/*   Updated: 2022/09/11 02:58:30 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
#include <stdbool.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*P_IMG;
	void	*W_IMG;
	void	*C_IMG;
	void	*BG_IMG;
	char	**map;
	int		collectible;
	int		x;
	int		y;
	int		step_count;
}	t_data;

typedef struct s_utils
{
	char	**map_fill;
	int		i;
	int		j;
	int		count_collectible;
	int		total_collectible;
	int		tab[256];
	bool	exit;
}	t_utils;

int		ft_copy_map(t_data *data, t_utils *utils, char *argv);
void	get_map(t_data *data, t_utils *utils, char *argv);
int		ft_count_line(char *argv);
int		ft_check_each(t_data *data);
int		ft_check_wall(t_data *data, char *argv);
int		ft_check_rectangle_map(t_data *data);
int		ft_count_collectible(t_data *data, t_utils *utils);

void	ft_flood_fill(t_utils *utils);
void	ft_change_to_player(t_utils *utils, int i, int j);
int		ft_check_player(t_utils *utils, int i, int j);
void	ft_check_exit(t_utils *utils);
int		ft_check_path(t_data *data, t_utils *utils);
void	init_var(t_utils *utils);
int		ft_check_map(t_data *data, char *argv);

#endif