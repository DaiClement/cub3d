/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:49:28 by cdai              #+#    #+#             */
/*   Updated: 2020/02/24 12:38:39 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_set_path(char **path, char **splited_data)
{
	if (*path)
		return (ft_print_error("A path appears twice"));
	else if (!splited_data[1])
		return (ft_print_error("Path should have 1 argument"));
	else if (splited_data[2])
		return (ft_print_error("Path has too much argument"));
	else if (!ft_check_file_extention(splited_data[1], ".xpm"))
		return (ft_print_error("Path issue"));
	else if (!(*path = ft_strdup(splited_data[1])))
		return (ft_print_error("Malloc error (ft_handle_path)"));
	return (1);
}

int			ft_handle_path(t_scene *scene, char **splited_data, int elem_type)
{
	if (elem_type == 4)
		return (ft_set_path(&scene->sprite, splited_data));
	else
		return (ft_set_path(&scene->path[elem_type], splited_data));
}
