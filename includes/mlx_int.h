/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:26:46 by cdai              #+#    #+#             */
/*   Updated: 2020/03/07 10:40:33 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INT_H
# define MLX_INT_H

# define MAX_EVENT 32
# define MAX_PIXEL_NB 200000
# define UNIQ_BPP 4
# define FONT_WIDTH 10
# define FONT_HEIGHT 20

//# include <OpenGL/gl.h>
# include <GL/gl.h>

typedef struct	s_glsl_info
{
	GLuint	pixel_vshader;
	GLuint	pixel_fshader;
	GLuint	pixel_program;
	GLint	loc_pixel_position;
	GLint	loc_pixel_texture;
	GLint	loc_pixel_winhalfsize;

	GLuint	image_vshader;
	GLuint	image_fshader;
	GLuint	image_program;
	GLint	loc_image_position;
	GLint	loc_image_winhalfsize;
	GLint	loc_image_texture;
	GLint	loc_image_pos;
	GLint	loc_image_size;

	GLuint	font_vshader;
	GLuint	font_fshader;
	GLuint	font_program;
	GLint	loc_font_position;
	GLint	loc_font_winhalfsize;
	GLint	loc_font_texture;
	GLint	loc_font_color;
	GLint	loc_font_posinwin;
	GLint	loc_font_posinatlas;
	GLint	loc_font_atlassize;
}				t_glsl_info;

typedef struct	s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	GLfloat					vertexes[8];
	struct s_mlx_img_list	*next;
}				t_mlx_img_list;

typedef struct	s_mlx_img_ctx
{
	GLuint					texture;
	GLuint					vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}				t_mlx_img_ctx;

typedef struct	s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}				t_mlx_win_list;

typedef struct	s_mlx_ptr
{
	void			*appid;
	t_mlx_win_list	*win_list;
	t_mlx_img_list	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	t_mlx_img_list	*font;
	int				main_loop_active;
}				t_mlx_ptr;

#endif
