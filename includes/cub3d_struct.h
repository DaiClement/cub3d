/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:05:51 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 17:47:00 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct	s_map
{
	char	**data;
	int		empty_line;
	int		width;
	int		height;
	int		start_pos_x;
	int		start_pos_y;
	char	start_angle;
	int		nb_sprite;
}				t_map;

typedef struct	s_scene
{
	char	*path[4];
	char	*sprite;
	int		width;
	int		height;
	char	floor_is_set;
	char	ceilling_is_set;
	char	floor[4];
	char	ceilling[4];
	t_map	map;
}				t_scene;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct	s_camera
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_camera;

typedef struct	s_mov_flags
{
	double	walk_speed;
	double	rotation_speed;
	char	forward;
	char	backward;
	char	turn_right;
	char	turn_left;
	char	mov_right;
	char	mov_left;
}				t_mov_flags;

typedef struct	s_image
{
	int		width;
	int		height;
	void	*image;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		img_size;
}				t_image;

typedef struct	s_calcul
{
	int			init_pos;
	int			pos;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	double		lign_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	double		tex_x;
	double		tex_y;
	int			temp;
}				t_calcul;

typedef struct	s_sprite
{
	char					color[4];
	double					x;
	double					y;
	double					sprite_x;
	double					sprite_y;
	double					inv_det;
	double					transform_x;
	double					transform_y;
	int						screen_x;
	int						height;
	int						draw_start_y;
	int						draw_end_y;
	int						width;
	int						draw_start_x;
	int						draw_end_x;
	int						tex_x;
	int						tex_y;
}				t_sprite;

typedef struct	s_game_data
{
	t_scene			scene;
	t_mlx			mlx;
	t_camera		camera;
	t_mov_flags		mov_flags;
	t_image			working_img;
	t_image			textures[4];
	t_image			sprite;
	t_calcul		calcul;
	t_list			*sprite_list;
}				t_game_data;

#endif
