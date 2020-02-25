/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:03:38 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 15:26:13 by cdai             ###   ########.fr       */
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

int		ft_launch_game(char *filename);
int		ft_parse_cub(t_scene *scene, char *filename);
int		ft_check_file_extention(char *filename, char *extention);
void	ft_free_gnl_value(char **line, char **splited_data);
int		ft_check_scene_element(t_scene *scene, char **splited_data);
int		ft_set_resolution(t_scene *scene, char **splited_data);
int		ft_check_atoi_max_min(char *nb);
int		ft_str_isdigit(char *str);
int		ft_handle_path(t_scene *scene, char **splited_data, int elem_type);
int		ft_handle_color(t_scene *scene, char **splited_data, int elem_type);
int		ft_handle_map(t_map *map, char **splited_data);
int		ft_check_n_parse_map(t_map *map);
int		ft_print_error(char *error_msg);
void	ft_init_orientation(t_game_data *data);
int		ft_prepare_textures_n_sprite(t_game_data *data);
int		ft_free_data(t_game_data *data);
void	ft_free_scene(t_scene *scene);
int		ft_prepare_mlx(t_game_data *data);
void	ft_handle_image(t_game_data *data);
void	ft_handle_mouvement(t_game_data *data);
int		ft_raycasting(t_game_data *data, t_sprite *sprite_list);
int		ft_play_game(t_game_data *data);
int		ft_handle_keyboard(t_game_data *data);
void	ft_put_pixel_on_column(t_game_data *data, double x);
void	ft_put_pixel(char *img_data, char *color, int pos);
int		ft_handle_sprite(t_game_data *data, double perp_wall_dist, double x,
	t_sprite *sprite_list);

#endif
