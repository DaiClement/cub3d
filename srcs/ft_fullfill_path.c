/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:24:31 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 21:12:24 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fullfill_path(t_scene **scene, char **splited_data, t_scene **status,
	int i)
{
	if ((*scene)->sprite[i])
		return (-1);
	if (!splited_data[1] || splited_data[2])
		return (-1);
	(*scene)->sprite[i] = ft_strdup(splited_data[1]);
	(*status)->sprite[i] = ft_strdup(" ");
	return (1);
}
