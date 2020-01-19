/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:23:27 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 22:38:52 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"

typedef	struct	s_scene
{
	char	*(sprite[5]);
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
	int		line_length;
	char	orientation;
}				t_mapstatus;

int				ft_check_file_extention(const char *filename,
	const char *extention);
t_scene			*ft_parse_cub(const char *filename);
void			ft_launch_game(const char *filename);
t_scene			*ft_fullfill_scene(const char *filename);
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
int				ft_check_n_parse_map(t_scene **scene, t_scene **status);

#endif
