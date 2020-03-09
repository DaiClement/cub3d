/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:09:44 by cdai              #+#    #+#             */
/*   Updated: 2020/03/09 11:06:46 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_read_n_set_element(t_scene *scene, int fd)
{
	char	*line;
	char	**splited_data;
	int		gnl_value;

	gnl_value = get_next_line(fd, &line);
	if (gnl_value == 1 || gnl_value == 0)
	{
		splited_data = ft_split(line, ' ');
		if (ft_strlen(line) > 500)
		{
			ft_print_error("A Line is too long");
			return (ft_free_gnl_value(&line, splited_data));
		}
		else if (!(ft_check_scene_element(scene, splited_data, line)))
			return (ft_free_gnl_value(&line, splited_data));
		ft_free_gnl_value(&line, splited_data);
	}
	else
	{
		ft_print_error("GNL error");
		return (ft_free_gnl_value(&line, splited_data));
	}
	return (gnl_value);
}

static int	ft_check_n_open_cub(char *filename)
{
	int	fd;

	if (!ft_check_file_extention(filename, ".cub"))
	{
		ft_print_error("File extention must be \".cub\"");
		return (-1);
	}
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_print_error("Open fails");
		return (-1);
	}
	return (fd);
}

int			ft_parse_cub(t_scene *scene, char *filename)
{
	int		fd;
	int		gnl_value;

	gnl_value = 1;
	if ((fd = ft_check_n_open_cub(filename)) == -1)
		return (0);
	while (gnl_value == 1)
	{
		if ((gnl_value = ft_read_n_set_element(scene, fd)) == -1)
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	if (!scene->map.data)
		return (ft_print_error("No map or not enough argument"));
	if (!ft_check_n_parse_map(&scene->map))
		return (0);
	return (1);
}
