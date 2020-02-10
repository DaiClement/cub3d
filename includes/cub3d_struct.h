/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:26:44 by cdai              #+#    #+#             */
/*   Updated: 2020/02/10 17:26:45 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef	struct	s_scene
{
	char	*sprite[5];
	int		resolution[2];
	char	floor[4];
	char	ceilling[4];
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

typedef struct	s_sprite
{
	char	color[4];
	double	x;
	double	y;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		texX;
	int		texY;
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
	t_list		*sprite_list;
	int			nb_sprite;
}				t_game_data;

#endif
