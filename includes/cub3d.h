/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:23:27 by cdai              #+#    #+#             */
/*   Updated: 2020/02/08 19:24:22 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "cub3d_struct.h"

int				ft_check_file_extention(const char *filename,
	const char *extention);
t_scene			*ft_parse_cub(t_game_data *data, const char *filename);
void			ft_launch_game(const char *filename);
void			*ft_free_all(t_scene **scene, t_scene **status, char **line,
	char **splited_data);
int				ft_check_scene_element(t_scene **scene, char **splited_data,
	t_scene **status);
int				ft_fullfill_resolution(t_scene **scene, char **splited_data,
	t_scene **status);
int				ft_fullfill_path(t_scene **scene, char **splited_data,
	t_scene **status, int i);
int				ft_fullfill_floor(t_scene **scene, char **splited_data,
	t_scene **status);
int				ft_fullfill_ceilling(t_scene **scene, char **splited_data,
	t_scene **status);
int				ft_check_atoi_max_min(char *nb);
int				ft_isinrange(int tocheck, int min, int max);
int				ft_fullfill_map(t_scene **scene, char **splited_data,
	t_scene **status);
int				ft_check_n_parse_map(t_game_data *data, t_scene **status);
int				ft_put_map_to_image(t_scene *scene, void *win_ptr, void *image);
int				ft_handle_image(t_game_data *data);
int				ft_handle_keyboard(t_game_data *data);
int				ft_prepare_images(t_game_data *data);
void			ft_handle_mouvement(t_game_data *data);
void			ft_rotate_left(t_game_data *data);
void			ft_rotate_right(t_game_data *data);
int				ft_handle_sprite(t_game_data *data, double perpWallDist, double x);

#endif
