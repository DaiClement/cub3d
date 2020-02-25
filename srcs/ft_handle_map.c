/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:07:24 by cdai              #+#    #+#             */
/*   Updated: 2020/02/24 11:43:14 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_free_handle_map(char *temp, char *result)
{
	ft_print_error("Malloc error (ft_free_handle_map)");
	free(temp);
	temp = NULL;
	free(result);
	result = NULL;
	return (0);
}

static int	ft_strjoin_map(t_map *map, char *temp, char *result)
{
	if (!(temp = ft_strjoin(result, "\n")))
		return (ft_free_handle_map(temp, result));
	free(result);
	result = *map->data;
	if (!(*map->data = ft_strjoin(result, temp)))
		return (ft_free_handle_map(temp, result));
	free(temp);
	free(result);
	return (1);
}

static int	ft_init_map(t_map *map)
{
	if (!(map->data = ft_calloc(2, sizeof(*map->data))))
		return (ft_free_handle_map(NULL, NULL));
	if (!(*map->data = ft_calloc(1, sizeof(**map->data))))
		return (ft_free_handle_map(NULL, NULL));
	return (1);
}

static int	ft_check_variable_handle_map(t_map *map, char **splited_data)
{
	if (!*splited_data)
	{
		if (map->data)
			map->empty_line = 1;
		return (1);
	}
	if (splited_data[0][0] != '1')
	{
		if (map->data)
			return (ft_print_error("Map format issue or element after map"));
		else
			return (ft_print_error("Wrong element or too much element"));
	}
	if (map->empty_line && *splited_data && map->data)
		return (ft_print_error("Empty line in the map"));
	if (!map->data)
		if (!ft_init_map(map))
			return (ft_free_handle_map(NULL, NULL));
	return (-1);
}

int			ft_handle_map(t_map *map, char **splited_data)
{
	int		i;
	char	*temp;
	char	*result;

	i = ft_check_variable_handle_map(map, splited_data);
	if (!i)
		return (i);
	else if (i == 1)
		return (i);
	if (!(result = ft_calloc(1, sizeof(*result))))
		return (ft_free_handle_map(NULL, NULL));
	while (splited_data[++i])
	{
		temp = result;
		if (!(result = ft_strjoin(temp, splited_data[i])))
			return (ft_free_handle_map(temp, NULL));
		free(temp);
	}
	return (ft_strjoin_map(map, temp, result));
}
