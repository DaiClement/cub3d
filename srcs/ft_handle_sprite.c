/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:13:35 by cdai              #+#    #+#             */
/*   Updated: 2020/02/10 17:33:09 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_is_black(char *color)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (color[i] != 0)
			return 0;
		i++;
	}
	return 1;
}

int ft_handle_sprite(t_game_data *data, double perpWallDist, double x)
{
	int numSprites = data->nb_sprite;
	int y;
	t_sprite	*sprite;
	t_list      *temp_list = data->sprite_list;
	int init_pos;
	int pos;
	int temp;

	if (numSprites)
	{
		//SPRITE CASTING
		//sort sprites from far to close
		while (temp_list)
		{
			sprite = (t_sprite*)temp_list->content;
			sprite->spriteX = sprite->x - data->camera->pos_x;
			sprite->spriteY = sprite->y - data->camera->pos_y;

			sprite->invDet = 1.0 / (data->camera->plane_x * data->camera->dir_y - data->camera->dir_x * data->camera->plane_y); //required for correct matrix multiplication

			sprite->transformX = sprite->invDet * (data->camera->dir_y * sprite->spriteX - data->camera->dir_x * sprite->spriteY);
			sprite->transformY = sprite->invDet * (-data->camera->plane_y * sprite->spriteX + data->camera->plane_x * sprite->spriteY); //this is actually the depth inside the screen, that what Z is in 3D

			if (sprite->transformY > 0 && sprite->transformY < perpWallDist)
			{
				sprite->spriteScreenX = ((data->scene->resolution[0] / 2) * (1 + sprite->transformX / sprite->transformY));
				sprite->spriteWidth = fabs(data->scene->resolution[1] / (sprite->transformY));
				sprite->drawStartX = -sprite->spriteWidth / 2 + sprite->spriteScreenX;
				if (sprite->drawStartX < 0)
					sprite->drawStartX = 0;
				sprite->drawEndX = sprite->spriteWidth / 2 + sprite->spriteScreenX;
				if (sprite->drawEndX >= data->scene->resolution[0])
					sprite->drawEndX = data->scene->resolution[0] - 1;

				if (x >= sprite->drawStartX && x < sprite->drawEndX)
				{
					//calculate height of the sprite on screen
					sprite->spriteHeight = fabs((data->scene->resolution[1] / (sprite->transformY))); //using 'transformY' instead of the real distance prevents fisheye
					//calculate lowest and highest pixel to fill in current stripe
					sprite->drawStartY = -sprite->spriteHeight / 2 + data->scene->resolution[1] / 2;
					if (sprite->drawStartY < 0)
						sprite->drawStartY = 0;
					sprite->drawEndY = sprite->spriteHeight / 2 + data->scene->resolution[1] / 2;
					if (sprite->drawEndY >= data->scene->resolution[1])
						sprite->drawEndY = data->scene->resolution[1] - 1;

					//calculate width of the sprite
					sprite->texX = (x - (-sprite->spriteWidth / 2 + sprite->spriteScreenX)) * data->sprite[4].width / sprite->spriteWidth;
					y = sprite->drawStartY;
					init_pos = - x * data->image->bits_per_pixel / 8 - 1;
					while (y < sprite->drawEndY)
					{
						sprite->texY = (((y + (-data->scene->resolution[1] + sprite->spriteHeight) / 2) * data->sprite[4].height) / sprite->spriteHeight);
						temp = sprite->texY * data->sprite[4].size_line + sprite->texX * 4;
						if (!ft_is_black(&data->sprite[4].img_data[temp]))
						{
							pos =
								init_pos +
								y * data->image->size_line;
							ft_put_pixel(data->image->img_data, &data->sprite[4].img_data[temp], pos);
						}
						y++;
					}
				}
			}
			temp_list = temp_list->next;
		}
	}
	return 1;
}
