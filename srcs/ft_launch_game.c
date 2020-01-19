/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:56:01 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 22:39:55 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_launch_game(const char *filename)
{
	t_scene	*scene;

	if (!(scene = ft_parse_cub(filename)))
		return ;
printf("Resolution x: %d\n",scene->resolution[0]);
printf("Resolution y: %d\n",scene->resolution[1]);
printf("North textures path: %s\n", scene->sprite[0]);
printf("South textures path: %s\n", scene->sprite[1]);
printf("West textures path: %s\n", scene->sprite[2]);
printf("East textures path: %s\n", scene->sprite[3]);
printf("Sprite textures path: %s\n", scene->sprite[4]);
printf("Floor color RGBA: %d,%d,%d,%d\n", scene->floor[0], scene->floor[1], scene->floor[2], scene->floor[3]);
printf("Ceilling color RGBA: %d,%d,%d,%d\n", scene->ceilling[0], scene->ceilling[1], scene->ceilling[2], scene->ceilling[3]);
int i = 0;
printf("Map : \n");
while (scene->map[i])
{
	printf("%s\n", scene->map[i]);
	i++;
}
printf("Orientation : %c\n", scene->orientation);
	ft_free_all(&scene, NULL, NULL, NULL);
}
