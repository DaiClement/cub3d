/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:40:46 by cdai              #+#    #+#             */
/*   Updated: 2020/01/11 22:10:02 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_scene(t_scene **scene)
{
	int	i;

	i = 0;
	if (*scene)
	{
		while (i < 5)
		{
			if ((*scene)->sprite[i])
				free((*scene)->sprite[i]);
			i++;
		}
//		free((*scene)->map);
	}
	free(*scene);
	*scene = 0;
}
