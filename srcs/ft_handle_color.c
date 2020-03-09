/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:02:12 by cdai              #+#    #+#             */
/*   Updated: 2020/03/09 14:19:12 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_isinrange(int nb, int min, int max)
{
	if (nb < min || nb > max)
		return (0);
	return (1);
}

static int	ft_check_format(char *data)
{
	int	i;
	int	nb_comma;

	i = 0;
	nb_comma = 0;
	while (data[i])
	{
		if (!ft_isdigit(data[i]) || nb_comma == 3 ||
		!ft_check_atoi_max_min(data + i) ||
		!ft_isinrange(ft_atoi(data + i), 0, 255))
			return (0);
		while (ft_isdigit(data[i]))
			i++;
		if ((data[i] != 0 && nb_comma == 2) || (data[i] != ',' && nb_comma < 2))
			return (0);
		else if (data[i] == ',')
			i++;
		nb_comma++;
	}
	if (i > 0 && data[i - 1] == ',')
		return (0);
	return (1);
}

static int	ft_pre_set_color(char **splited_data, char *color_is_set)
{
	if (*color_is_set)
		return (ft_print_error("A color appears twice"));
	else if (!splited_data[1] || splited_data[2])
		return (ft_print_error("Color should have 1 argument"));
	else if (ft_check_format(splited_data[1]))
		return (1);
	else
		return (ft_print_error("Color not R,G,B format or out of [0,255]"));
}

static int	ft_set_color(char scene_color[3], char **splited_data,
char *color_is_set)
{
	int		i;
	int		nb_comma;

	i = 0;
	nb_comma = 0;
	if (!ft_pre_set_color(splited_data, color_is_set))
		return (0);
	while (splited_data[1][i])
	{
		(scene_color)[2 - nb_comma] = ft_atoi(splited_data[1] + i);
		while (ft_isdigit(splited_data[1][i]))
			i++;
		if (splited_data[1][i] == ',')
			i++;
		nb_comma++;
	}
	*color_is_set = 1;
	return (1);
}

int			ft_handle_color(t_scene *scene, char **splited_data, int elem_type)
{
	if (elem_type == 6)
		return (ft_set_color(scene->floor, splited_data, &scene->floor_is_set));
	else
		return (ft_set_color(scene->ceilling, splited_data,
		&scene->ceilling_is_set));
}
