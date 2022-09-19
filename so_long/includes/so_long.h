/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:54:49 by fwong             #+#    #+#             */
/*   Updated: 2022/09/19 17:38:58 by fwong            ###   ########.fr       */
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
	char	**map_fill;
	int		count_P;
	int		count_E;
	int		count_C;
	int		total_C;
	int		x;
	int		y;
	int		width;
	int		height;
	int		step_count;
	bool	exit;
}	t_data;

/* ************************************************************************* */
/*                                    Parsing                                */
/* ************************************************************************* */

void	get_map(t_data *data, char *argv);

// check path functions
int		ft_check_player(t_data *data, int i, int j);
void	ft_change_to_player(t_data *data, int i, int j);
int		ft_check_exit(t_data *data);
void	ft_flood_fill(t_data *data);
int		ft_check_path(t_data *data);

// check valid map functions
int		ft_check_each(t_data *data);
int		ft_check_wall(t_data *data, char *argv);
int		ft_check_rectangle_map(t_data *data);
int		ft_check_map(t_data *data, char *argv);

/* ************************************************************************* */
/*                                    Minilibx                               */
/* ************************************************************************* */

// display map
int	init_ptr(t_data *data);
void	init_img(t_data *data);
int	ft_display_map(t_data *data);
int	start_game(t_data *data);
// int ft_update_map(t_data *data);
// int	ft_close_window(t_data *data);
// int	ft_close(t_data *data);

// move functions
int		ft_find_player(t_data *data);
int		ft_move(int keycode, t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);

/* ************************************************************************* */
/*                                    Utils                                  */
/* ************************************************************************* */

int		ft_count_line(char *argv, t_data *data);
int		ft_copy_map(t_data *data);
void	ft_init_struct(t_data *data);

// free functions
void	ft_free_map(t_data *data);
void	ft_free_map_fill(t_data *data);
int		ft_clean_before_exit(t_data *data);

#endif