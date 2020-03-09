/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:07:24 by cdai              #+#    #+#             */
/*   Updated: 2020/03/05 17:02:42 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_init_map_data(void)
{
	char	**result;

	if (!(result = ft_calloc(2, sizeof(*result))))
		return (result);
	else if (!(*result = ft_calloc(1, sizeof(**result))))
		return (result);
	return (result);
}

int			ft_handle_map(t_map *map, char *line)
{
	char *temp;

	if (*line && map->empty_line && map->data)
		return (ft_print_error("Empty line in map"));
	else if (!*line)
	{
		if (map->data)
			map->empty_line = 1;
		return (1);
	}
	if (!map->data)
		if (!(map->data = ft_init_map_data()))
			return (ft_print_error("Malloc error (ft_handle_map)"));
	if (!(temp = ft_strjoin(*map->data, line)))
		return (ft_print_error("ft_strjoin error (ft_handle_map)"));
	free(*map->data);
	if (!(*map->data = ft_strjoin(temp, "\n")))
	{
		free(temp);
		return (ft_print_error("ft_str_join error (ft_handle_map)"));
	}
	free(temp);
	return (1);
}
