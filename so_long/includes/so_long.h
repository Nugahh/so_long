/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:54:49 by fwong             #+#    #+#             */
/*   Updated: 2022/09/12 22:51:51 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************* */
/*                                    Library                                */
/* ************************************************************************* */

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdbool.h>

/* ************************************************************************* */
/*                                    Structure                              */
/* ************************************************************************* */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*P_IMG;
	void	*W_IMG;
	void	*C_IMG;
	void	*F_IMG;
	void	*EC_IMG;
	void	*EO_IMG;
	char	**map;
	int		collectible;
	int		x;
	int		y;
	int		width;
	int		height;
	int		step_count;
}	t_data;

typedef struct s_utils
{
	char	**map_fill;
	int		count_collectible;
	int		total_collectible;
	bool	exit;
}	t_utils;

/* ************************************************************************* */
/*                                    Parsing                                */
/* ************************************************************************* */

void	get_map(t_data *data, t_utils *utils, char *argv);

// check path functions
int		ft_check_player(t_utils *utils, int i, int j);
void	ft_change_to_player(t_utils *utils, int i, int j);
void	ft_check_exit(t_utils *utils);
void	ft_flood_fill(t_utils *utils);
int		ft_check_path(t_data *data, t_utils *utils);

// check valid map functions
int		ft_check_each(t_data *data);
int		ft_check_wall(t_data *data, char *argv);
int		ft_check_rectangle_map(t_data *data);
int		ft_check_map(t_data *data, char *argv);

/* ************************************************************************* */
/*                                    Minilibx                               */
/* ************************************************************************* */

// display map
int	ft_display_map(t_data *data);
int	ft_close_window(t_data *data);
int	ft_close(t_data *data);

// move functions
int		ft_find_player(t_data *data);
int		ft_move(t_data *data, t_utils *utils, int keycode);
void	ft_move_up(t_data *data, t_utils *utils);
void	ft_move_down(t_data *data, t_utils *utils);
void	ft_move_left(t_data *data, t_utils *utils);
void	ft_move_right(t_data *data, t_utils *utils);

/* ************************************************************************* */
/*                                    Utils                                  */
/* ************************************************************************* */

int		ft_count_collectible(t_data *data, t_utils *utils);
int		ft_count_line(char *argv);
int		ft_copy_map(t_data *data, t_utils *utils, char *argv);
void	ft_init_struct(t_data *data, t_utils *utils);

#endif