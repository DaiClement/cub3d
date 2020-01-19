/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:09:36 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 21:14:13 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_init_map(t_scene **scene, t_scene **status)
{
	if (!((*status)->map = ft_calloc(2, sizeof(*(*status)->map))))
		return (0);
	if (!((*scene)->map = ft_calloc(2, sizeof(*(*scene)->map))))
		return (0);
	return (1);
}

int			ft_fullfill_map(t_scene **scene, char **splited_data,
	t_scene **status)
{
	int		i;
	char	*temp;
	char	*result;

	i = 0;
	if (!(*status)->map)
		if (!ft_init_map(scene, status))
			return (-1);
	if (!(*(*scene)->map))
		*(*scene)->map = ft_calloc(1, sizeof((*(*scene)->map)));
	result = ft_calloc(1, 1);
	while (splited_data[i])
	{
		temp = result;
		result = ft_strjoin(temp, splited_data[i]);
		free(temp);
		i++;
	}
	temp = ft_strjoin(result, "\n");
	free(result);
	result = *(*scene)->map;
	*(*scene)->map = ft_strjoin(result, temp);
	free(temp);
	free(result);
	return (1);
}
