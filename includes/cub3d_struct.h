/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:26:44 by cdai              #+#    #+#             */
/*   Updated: 2020/02/06 14:50:55 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef	struct	s_scene
{
	char	*sprite[5];
	int		resolution[2];
	int		floor[4];
	int		ceilling[4];
	char	**map;
	char	orientation;
}				t_scene;

typedef struct	s_mapstatus
{
	int		started;
	int		ended;
	int		width;
	int		heigth;
	char	orientation;
}				t_mapstatus;

typedef struct	s_camera
{
	char	start_angle;
	double	angle;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_camera;

typedef struct	s_calcul
{
	int width;
	int height;
}				t_calcul;

typedef struct	s_sprite
{
	double	x;
	double	y;
	char	*texture;
}				t_sprite;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef	struct	s_image
{
	int		width;
	int		height;
	void	*image;
	char	*img_data;
	int		bits_per_pixel;
	int 	size_line;
	int		endian;
}				t_image;

typedef struct	s_mov_flags
{
	double		walk_speed;
	double		rotation_speed;
	char		forward;
	char		backward;
	char		turn_right;
	char		turn_left;
	char		mov_right;
	char		mov_left;
}				t_mov_flags;

typedef struct	s_game_data
{
	t_scene		*scene;
	t_mapstatus	*mapstatus;
	t_camera	*camera;
	t_mlx		*mlx;
	t_image		*image;
	t_image		sprite[5];
	t_mov_flags	*mov_flags;
	t_calcul	*calcul;
}				t_game_data;

#endif
