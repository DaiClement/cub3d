/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:02:58 by cdai              #+#    #+#             */
/*   Updated: 2020/02/08 19:23:19 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_put_pixel1(char *img_data, char *color, int pos)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		img_data[pos - k] = color[3 - k];
		k++;
	}
}

int	ft_is_black(char *color)
{
	int i = 0;

	while (i < 4)
	{
		if (color[i] != 0)
			return 0;
		i++;
	}
	return 1;
}

int	ft_handle_image(t_game_data *data)
{
	//	int	is_sprite = 0;
	// taille de la projection
	//	double w = data->scene->resolution[0];
	//	double h = data->scene->resolution[1];
	double x = 0;
	double y = 0;

	ft_handle_mouvement(data);	
	char color[4];
	while (x < data->scene->resolution[0])
	{
		//Position de départ et data->camera->direction du rayon
		double cameraX = (2*x/data->scene->resolution[0])-1;// position de la colonne par rapport au centre de l’écran
		double rayPosX = data->camera->pos_x;// position de départ du rayon sur X
		double rayPosY = data->camera->pos_y;// position de départ du rayon sur Y
		double rayDirX = data->camera->dir_x + data->camera->plane_x * cameraX;// data->camera->direction du rayon sur X
		double rayDirY = data->camera->dir_y + data->camera->plane_y * cameraX;// data->camera->direction du rayon sur Y
		// sur quelle case est la caméra
		int mapX = (int)(rayPosX);
		int mapY = (int)(rayPosY);
		// longueur du rayon
		double sideDistX = 0;
		double sideDistY = 0;
		// longueur du rayon entre chaque intersection
		double deltaDistX = sqrt(1+(rayDirY*rayDirY)/(rayDirX*rayDirX));
		double deltaDistY = sqrt(1+(rayDirX*rayDirX)/(rayDirY*rayDirY));
		// data->camera->direction du vecteur sur X et Y (+1 ou -1)
		int stepX = 0;
		int stepY = 0;
		double hit = 0;//le rayon touche un mur ou pas
		int side = 0;//quelle orientation à le mur (nord/sud ou est/ouest) dans la map 
		double perpWallDist = 0;// distance corrigée du rayon
		//calcule le vecteur de direction et la longueur entre deux segments
		if (rayDirX < 0)
		{
			stepX = -1;// vecteur de direction
			sideDistX = (rayPosX - mapX) * deltaDistX;// distance
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
		// tant que le rayon ne rencontre pas de mur
		while (hit == 0)
		{
			//			printf("sideDistX :%f, sideDistY :%f\n", sideDistX, sideDistY);
			//Passe à la case suivante sur X ou Y
			if (sideDistX<sideDistY)
			{
				sideDistX += deltaDistX;// agrandis le rayon
				mapX += stepX;// prochaine case ou case précédente sur X
				if (mapX < data->camera->pos_x)
					side = 2;
				else
					side = 3;
			}
			else
			{
				sideDistY += deltaDistY;// agrandis le rayon
				mapY += stepY;// prochaine case ou case précédente sur Y
				if (mapY < data->camera->pos_y)
					side = 0;
				else
					side = 1;
			}
			if (data->scene->map[mapY][mapX] == '1')
			{
				hit=1;// stoppe la boucle 
			}
		}
		// Calcule la distance corrigée pour la projection
		if (side > 1)
			perpWallDist = fabs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
		else
			perpWallDist = fabs((mapY-rayPosY+(1-stepY)/2)/rayDirY);
		//Calcule la hauteur de la ligne à tracer
		double hauteurLigne = fabs(data->scene->resolution[1] / perpWallDist);
		//Calcule les pixels max haut et max bas de la colonne à tracer
		double drawStart = (int)(-hauteurLigne/2+data->scene->resolution[1]/2);
		double drawEnd = (int)(hauteurLigne/2+data->scene->resolution[1]/2);
		// limite les zones de tracé à l'écran uniquement
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= data->scene->resolution[1])
			drawEnd = data->scene->resolution[1]-1;
		int pos = 0;
		// tracer la colonne
		//trace le sol de la fin du mur au bas de l'écran
		y=drawEnd;
		while (y < data->scene->resolution[1])
		{
			pos =   
				4 *
				data->scene->resolution[0] *
				data->scene->resolution[1] -
				1 -
				(int)y * data->image->size_line -
				(int)x * data->image->bits_per_pixel / 8;
			int i = 0;
			while (i < 4)
			{
				color[i] = data->scene->floor[3 - i];// couleur du texel
				i++;
			}
			ft_put_pixel1(data->image->img_data, color, pos);
			pos =
				4 * 
				data->scene->resolution[0] *
				data->scene->resolution[1] -
				1 -
				(int)(data->scene->resolution[1]-y-1) * data->image->size_line -
				(int)x * data->image->bits_per_pixel / 8;
			i = 0;
			while (i < 4)
			{
				color[i] = data->scene->ceilling[3 - i];// couleur du texel
				i++;
			}
			ft_put_pixel1(data->image->img_data, color, pos);
			y++;
		}
		// référence de la texture (-1 pour utiliser le 0 du tableau de textures)
		double wallX = 0;// la colonne exacte touchée transposée sur X
		//  si le mur est orienté est/ouest (sur Y)
		if (side < 2)
			wallX=rayPosX+((mapY-rayPosY+(1-stepY)/2)/rayDirY)*rayDirX;
		else
			wallX=rayPosY+((mapX-rayPosX+(1-stepX)/2)/rayDirX)*rayDirY;
		wallX -= floor(wallX);// arrondis à l’inférieur 
		// coordonnée x de la colonne dans la texture
		double texX = (wallX * data->sprite[0].width);
		texX = data->sprite[0].width - texX - 1;
		// trace la colonne
		y=drawStart;
		while (y<drawEnd)
		{
			double texY = (y * 2 - data->scene->resolution[1] + hauteurLigne) * (data->sprite[0].height/2)/hauteurLigne;// coordonnée Y du texel 
//			int i = 0;
			int temp = 0;
			temp = (int)(texY) * data->sprite[side].size_line + (int)(texX) * 4;
//			while (i < 4)
//			{
//				color[i] = data->sprite[side].img_data[temp + 3 - i];// couleur du texel
//				i++;
//			}
			pos =   
				data->scene->resolution[0] * data->scene->resolution[1] * 4 - 1 -
				(int)y * data->image->size_line -
				(int)x * data->image->bits_per_pixel / 8;
			ft_put_pixel1(data->image->img_data, &data->sprite[side].img_data[temp], pos);
			y++;
		}
		ft_handle_sprite(data, perpWallDist, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->image->image, 0, 0);
	return (0);
}

int	ft_handle_sprite(t_game_data *data, double perpWallDist, double x)
{
	(void)x;
	// ------------------------------------------------------------------------------------------
	int numSprites = 1;
	int spriteOrder[1];
	double spriteDistance[1];
	int i;
	int y;
	int stripe;
	t_sprite	sprite[1];
	sprite[0].x = 18.5;
	sprite[0].y = 2.5;
	//SPRITE CASTING
	//sort sprites from far to close
	i = 0;
	while (i < numSprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((data->camera->pos_x - sprite[i].x) * (data->camera->pos_x - sprite[i].x) + (data->camera->pos_y - sprite[i].y) * (data->camera->pos_y - sprite[i].y)); //sqrt not taken, unneeded
		i++;
	}
	//    sortSprites(spriteOrder, spriteDistance, numSprites);

	//after sorting the sprites, do the projection and draw them
	i = 0;
	while (i < numSprites)
	{
		//translate sprite position to relative to camera
		sprite[i].spriteX = sprite[spriteOrder[i]].x - data->camera->pos_x;
		sprite[i].spriteY = sprite[spriteOrder[i]].y - data->camera->pos_y;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		sprite[i].invDet = 1.0 / (data->camera->plane_x * data->camera->dir_y - data->camera->dir_x * data->camera->plane_y); //required for correct matrix multiplication

		sprite[i].transformX = sprite[i].invDet * (data->camera->dir_y * sprite[i].spriteX - data->camera->dir_x * sprite[i].spriteY);
		sprite[i].transformY = sprite[i].invDet * (-data->camera->plane_y * sprite[i].spriteX + data->camera->plane_x * sprite[i].spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		if(sprite[i].transformY > 0 && sprite[i].transformY < perpWallDist)
		{
			sprite[i].spriteScreenX = ((data->scene->resolution[0] / 2) * (1 + sprite[i].transformX / sprite[i].transformY));
			//calculate height of the sprite on screen
			sprite[i].spriteHeight = fabs((data->scene->resolution[1] / (sprite[i].transformY))); //using 'transformY' instead of the real distance prevents fisheye
			//calculate lowest and highest pixel to fill in current stripe
			sprite[i].drawStartY = -sprite[i].spriteHeight / 2 + data->scene->resolution[1] / 2;
			if(sprite[i].drawStartY < 0) sprite[i].drawStartY = 0;
			sprite[i].drawEndY = sprite[i].spriteHeight / 2 + data->scene->resolution[1] / 2;
			if(sprite[i].drawEndY >= data->scene->resolution[1]) sprite[i].drawEndY = data->scene->resolution[1] - 1;

			//calculate width of the sprite
			sprite[i].spriteWidth = fabs(data->scene->resolution[1] / (sprite[i].transformY));
			sprite[i].drawStartX = -sprite[i].spriteWidth / 2 + sprite[i].spriteScreenX;
			if(sprite[i].drawStartX < 0) sprite[i].drawStartX = 0;
			sprite[i].drawEndX = sprite[i].spriteWidth / 2 + sprite[i].spriteScreenX;
			if(sprite[i].drawEndX >= data->scene->resolution[0]) sprite[i].drawEndX = data->scene->resolution[0] - 1;

			stripe = (int)x;
if (stripe > sprite[i].drawStartX && stripe < sprite[i].drawEndX)
{
			//loop through every vertical stripe of the sprite on screen
//			stripe = sprite[i].drawStartX;
//			while (stripe < sprite[i].drawEndX)
//			{
				sprite[i].texX = (stripe - (-sprite[i].spriteWidth / 2 + sprite[i].spriteScreenX)) * data->sprite[4].width / sprite[i].spriteWidth;
				//1) it's in front of camera plane so you don't see things behind you
				//2) it's on the screen (left)
				//3) it's on the screen (right)
				//4) ZBuffer, with perpendicular distance
				y = sprite[i].drawStartY;
				while (y < sprite[i].drawEndY)
				{
//					int d = y - data->scene->resolution[1] / 2 + sprite[i].spriteHeight / 2; //256 and 128 factors to avoid floats
					sprite[i].texY = (((y - data->scene->resolution[1] / 2 + sprite[i].spriteHeight / 2) * data->sprite[4].height) / sprite[i].spriteHeight);
//if (0)
//{
					//          Uint32 color = texture[sprite[spriteOrder[i]].texture][texWidth * sprite[i].texY + sprite[i].texX]; //get current color from the texture
					//          if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
					int pos;
//					int j = 0;
					int temp = 0;
					temp = sprite[i].texY * data->sprite[4].size_line + sprite[i].texX * 4;
//					while (j < 4)
//					{
//						sprite[i].color[j] = data->sprite[4].img_data[temp + 3 - j];// couleur du texel
//						j++;
//					}
					pos =   
						- 1 +
						y * data->image->size_line -
						stripe * data->image->bits_per_pixel / 8;
					if (!ft_is_black(&data->sprite[4].img_data[temp]))
						ft_put_pixel1(data->image->img_data, &data->sprite[4].img_data[temp], pos);
//}
					y++;
				}
}
//				stripe++;
//			}
		}
		i++;
	}

	// ---------------------------------------------------------------------------------------------
	return 0;
}
