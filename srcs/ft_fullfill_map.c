/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:09:36 by cdai              #+#    #+#             */
/*   Updated: 2020/01/17 11:57:42 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fullfill_map(t_scene **scene, char **splited_data, t_scene **status)
{
	int i;

	(void)scene;
	i = 0;
	if (!(*status)->map)
		if (!((*status)->map = malloc(sizeof(*((*status)->map)))))
			return (-1);
	if (!(*scene)->map)
		if (!((*scene)->map = malloc(sizeof(*((*scene)->map)))))
			return (-1);
	while (splited_data[i])
	{
		printf("%s\n", splited_data[i]);
		(*(*scene)->map) = ft_strjoin();
		i++;
	}
	return (0);
}
