/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_resolution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:42:19 by cdai              #+#    #+#             */
/*   Updated: 2020/01/14 11:26:12 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fullfill_resolution(t_scene **scene, char **splited_data,
	t_scene **status)
{
	int i;

	i = 0;
	if ((*scene)->resolution[0] || (*scene)->resolution[1])
		return (-1);
	while (splited_data[i])
	{
		if (!splited_data[i])
			return (-1);
		else if (i > 2)
			return (-1);
		i++;
	}
	(*scene)->resolution[0] = ft_atoi(splited_data[1]);
	(*scene)->resolution[1] = ft_atoi(splited_data[2]);
	if (((*scene)->resolution[0] <= 2 && (*scene)->resolution[0] > 1920) ||
		((*scene)->resolution[1] <= 2 && (*scene)->resolution[1] > 1080))
		return (-1);
	(*status)->resolution[0] = 1;
	(*status)->resolution[1] = 1;
	return (0);
}
