/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:54:49 by fwong             #+#    #+#             */
/*   Updated: 2022/09/24 15:48:08 by fwong            ###   ########.fr       */
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
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <stdbool.h>

/* ************************************************************************* */
/*                                    Structure                              */
/* ************************************************************************* */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*w_img;
	void	*c_img;
	void	*f_img;
	void	*ec_img;
	void	*eo_img;
	char	**map;
	char	**map_fill;
	int		count_p;
	int		count_e;
	int		count_c;
	int		total_c;
	int		x;
	int		y;
	size_t	width;
	int		height;
	int		step_count;
	int		exit;
}	t_data;

/* ************************************************************************* */
/*                                    Parsing                                */
/* ************************************************************************* */

int		get_map(t_data *data, char *argv);

// check path functions
int		ft_check_player(t_data *data, int i, int j);
void	ft_change_to_player(t_data *data, int i, int j);
int		ft_check_exit(t_data *data);
int		ft_flood_fill(t_data *data);
int		ft_check_path(t_data *data);

// check valid map functions
int		ft_check_each(t_data *data);
int		ft_check_wall(t_data *data);
int		ft_check_rectangle_map(t_data *data);
int		ft_check_map(t_data *data);
int		ft_check_player_within_walls(t_data *data);

/* ************************************************************************* */
/*                                    Minilibx                               */
/* ************************************************************************* */

// display map
int		init_ptr(t_data *data);
int		init_img(t_data *data);
int		ft_display_map(t_data *data);
int		ft_img_to_window(t_data *data, int x, int y);
int		start_game(t_data *data);

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

// utils functions
int		ft_count_line(char *argv, t_data *data);
int		ft_copy_map(t_data *data);
void	ft_init_struct(t_data *data);
int		ft_remove_nl(t_data *data);

// free functions
void	ft_free_map(t_data *data);
void	ft_free_map_fill(t_data *data);
int		ft_clean_before_exit(t_data *data);
int		ft_clean_before_exit2(t_data *data);

// error functions
void	ft_error(t_data *data);
int		ft_check_ber_ext(char *argv);

#endif