/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:02:58 by cdai              #+#    #+#             */
/*   Updated: 2020/01/29 18:49:48 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_put_pixel(char *img_data, int color[4], int pos)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		img_data[pos - k] = color[k];
		k++;
	}
}

int	ft_test(t_game_data *data)
{
	int	is_sprite = 0;
	// taille de la projection
	double w = data->scene->resolution[0];
	double h = data->scene->resolution[1];
	double x = 0;
	double y = 0;
	// variables de stockage
	double oldDirX = 0;
	double oldPlaneX = 0;
	// avancer
	if (data->mov_flags->forward)
	{
		// si la prochaine case sur X est libre
		if (data->scene->map[(int)(data->camera->posY)][(int)(data->camera->posX + data->camera->dirX * data->mov_flags->walk_speed)] == '0')
			data->camera->posX += data->camera->dirX * data->mov_flags->walk_speed;// on avance sur X
		// si la prochaine case sur Y est libre
		if (data->scene->map[(int)(data->camera->posY + data->camera->dirY * data->mov_flags->walk_speed)][(int)(data->camera->posX)] == '0')
			data->camera->posY += data->camera->dirY * data->mov_flags->walk_speed;// on avance sur Y
	}
	// reculer
	if (data->mov_flags->backward)
	{
		if (data->scene->map[(int)(data->camera->posY)][(int)(data->camera->posX - data->camera->dirX * data->mov_flags->walk_speed)] == '0')
			data->camera->posX -= data->camera->dirX * data->mov_flags->walk_speed;// on recule sur X
		if (data->scene->map[(int)(data->camera->posY - data->camera->dirY * data->mov_flags->walk_speed)][(int)(data->camera->posX)] == '0')
			data->camera->posY -= data->camera->dirY * data->mov_flags->walk_speed;// on recule sur Y
	}
	// tourner a gauche
	if (data->mov_flags->turn_left)
	{
		oldDirX = data->camera->dirX;
		data->camera->dirX = data->camera->dirX * cos(-data->mov_flags->rotation_speed) - data->camera->dirY * sin(-data->mov_flags->rotation_speed);
		data->camera->dirY = oldDirX * sin(-data->mov_flags->rotation_speed) + data->camera->dirY * cos(-data->mov_flags->rotation_speed);
		printf("dirX :%f, dirY :%f\n", data->camera->dirX, data->camera->dirY);
		oldPlaneX = data->camera->planeX;
		data->camera->planeX = data->camera->planeX * cos(-data->mov_flags->rotation_speed) - data->camera->planeY * sin(-data->mov_flags->rotation_speed);
		data->camera->planeY = oldPlaneX * sin(-data->mov_flags->rotation_speed) + data->camera->planeY * cos(-data->mov_flags->rotation_speed);
		printf("plane :%f, planeY :%f\n", data->camera->planeX, data->camera->planeY);
	}
	// tourner a droite 
	if (data->mov_flags->turn_right)
	{
		oldDirX = data->camera->dirX;
		data->camera->dirX = data->camera->dirX * cos(data->mov_flags->rotation_speed) - data->camera->dirY * sin(data->mov_flags->rotation_speed);
		data->camera->dirY = oldDirX * sin(data->mov_flags->rotation_speed) + data->camera->dirY * cos(data->mov_flags->rotation_speed);
		printf("dirX :%f, dirY :%f\n", data->camera->dirX, data->camera->dirY);
		oldPlaneX = data->camera->planeX;
		data->camera->planeX = data->camera->planeX * cos(data->mov_flags->rotation_speed) - data->camera->planeY * sin(data->mov_flags->rotation_speed);
		data->camera->planeY = oldPlaneX * sin(data->mov_flags->rotation_speed) + data->camera->planeY * cos(data->mov_flags->rotation_speed);
		printf("plane :%f, planeY :%f\n", data->camera->planeX, data->camera->planeY);
	}
	// Latéral gauche
	if (data->mov_flags->mov_left)
	{
		// si le prochain tile sur X est libre on avance sur X
		if (data->scene->map[(int)(data->camera->posY)][(int)(data->camera->posX + data->camera->planeX  * data->mov_flags->walk_speed)] == '0')
			data->camera->posX += data->camera->planeX * data->mov_flags->walk_speed;
		// si le prochain tile sur Y est libre on avance sur Y
		if (data->scene->map[(int)(data->camera->posY + data->camera->planeY * data->mov_flags->walk_speed)][(int)(data->camera->posX)] == '0')
			data->camera->posY += data->camera->planeY * data->mov_flags->walk_speed;
	}
	// Latéral droite
	if (data->mov_flags->mov_right)
	{
		// si le prochain tile sur X est libre on recule sur X
		if (data->scene->map[(int)(data->camera->posY)][(int)(data->camera->posX - data->camera->planeX  * data->mov_flags->walk_speed)] == '0')
			data->camera->posX -= data->camera->planeX * data->mov_flags->walk_speed;
		// si le prochain tile sur Y est libre on recule sur Y
		if (data->scene->map[(int)(data->camera->posY - data->camera->planeY * data->mov_flags->walk_speed)][(int)(data->camera->posX)] == '0')
			data->camera->posY -= data->camera->planeY * data->mov_flags->walk_speed;
	}
	int data_len = data->scene->resolution[0] * data->scene->resolution[1] * 4 - 1;
	int color[4];
	while (x < w)
	{
		//Position de départ et data->camera->direction du rayon
		double cameraX = (2*x/w)-1;// position de la colonne par rapport au centre de l’écran
		double rayPosX = data->camera->posX;// position de départ du rayon sur X
		double rayPosY = data->camera->posY;// position de départ du rayon sur Y
		double rayDirX = data->camera->dirX + data->camera->planeX * cameraX;// data->camera->direction du rayon sur X
		double rayDirY = data->camera->dirY+data->camera->planeY*cameraX;// data->camera->direction du rayon sur Y
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
		double side = 0;//quelle orientation à le mur (nord/sud ou est/ouest) dans la map 
		double test = 0;
		double perpWallDist = 0;// distance corrigée du rayon
		//calcule le vecteur de data->camera->direction et la longueur entre deux segments
		if (rayDirX<0)
		{
			stepX=-1;// vecteur de data->camera->direction
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
			if (sideDistX<sideDistY)// && data->camera->dirX <= 0.0) // && data->camera->planeX < 0)
			{
				sideDistX += deltaDistX;// agrandis le rayon
				mapX += stepX;// prochaine case ou case précédente sur X
				side = 0;// orientation du mur
				test = 0;
			}
			//Passe à la case suivante sur X ou Y
//			else if (sideDistX<sideDistY && data->camera->dirX > 0.0)
//			{
//				sideDistX += deltaDistX;// agrandis le rayon
//				mapX += stepX;// prochaine case ou case précédente sur X
//				side = 0;// orientation du mur
//				test = 0;
//			}
			else
			{
				if (data->camera->dirY <= 0.0 && data->camera->planeX <= 0.0)
				{
				sideDistY += deltaDistY;// agrandis le rayon
				mapY += stepY;// prochaine case ou case précédente sur Y
				side = 1;// orientation du mur
				test = 1;
				}
				else// if (data->camera->dirY <= 0.0 && data->camera->planeX <= 0.0)
				{
				sideDistY += deltaDistY;// agrandis le rayon
				mapY += stepY;// prochaine case ou case précédente sur Y
				side = 1;// orientation du mur
				test = 0;
				}
			}
			// si le rayon rencontre un mur
//			if (data->scene->map[mapY][mapX] == '2')
//			{
//				hit=1;// stoppe la boucle
//				is_sprite = 1;
//			}
			if (data->scene->map[mapY][mapX] == '1')
			{
				hit=1;// stoppe la boucle 
				is_sprite = 0;
			}
		}
		// Calcule la distance corrigée pour la projection
		if (side == 0)
			perpWallDist = fabs((mapX-rayPosX+(1-stepX)/2)/rayDirX);
		else
			perpWallDist = fabs((mapY-rayPosY+(1-stepY)/2)/rayDirY);
		//Calcule la hauteur de la ligne à tracer
		double hauteurLigne = fabs(h / perpWallDist);
		//Calcule les pixels max haut et max bas de la colonne à tracer
		double drawStart = (int)(-hauteurLigne/2+h/2);
		double drawEnd = (int)(hauteurLigne/2+h/2);
		// limite les zones de tracé à l'écran uniquement
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= h)
			drawEnd = h-1;
		int pos = 0;
		// tracer la colonne
		y=drawStart;
		//trace le sol de la fin du mur au bas de l'écran
		y=drawEnd;
		while (y < h)
		{
			pos =   
				(int)y * data->image->size_line +
				(int)x * data->image->bits_per_pixel / 8;
			pos = data_len - pos;
			ft_put_pixel(data->image->img_data, data->scene->floor, pos);
			pos =   
				(int)(h-y-1) * data->image->size_line +
				(int)x * data->image->bits_per_pixel / 8;
			pos = data_len - pos;
			ft_put_pixel(data->image->img_data, data->scene->ceilling, pos);
			y++;
		}
		// référence de la texture (-1 pour utiliser le 0 du tableau de textures)
		char texNum = data->scene->map[mapY][mapX]-1;// trouve le chiffre de la case
		double wallX = 0;// la colonne exacte touchée transposée sur X
		//  si le mur est orienté est/ouest (sur Y)
		if (side==1)
			wallX=rayPosX+((mapY-rayPosY+(1-stepY)/2)/rayDirY)*rayDirX;
		else
			wallX=rayPosY+((mapX-rayPosX+(1-stepX)/2)/rayDirX)*rayDirY;
		wallX -= floor(wallX);// arrondis à l’inférieur 
		// coordonnée x de la colonne dans la texture
		double texX = (wallX * data->sprite[0].width);
		if (side == 0 && rayDirX > 0)
			texX = data->sprite[0].width - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = data->sprite[0].width - texX - 1;
		// trace la colonne
		y=drawStart;
		while (y<drawEnd)
		{
			double texY = (y * 2 - h + hauteurLigne) * (data->sprite[0].height/2)/hauteurLigne;// coordonnée Y du texel 
			int i = 0;
			int temp = 0; //(int)(texY) * data->sprite[0].size_line + (int)(texX) * 4;
//			if (is_sprite)
//			{
//				while (i < 4)
//				{
//					color[i] = data->sprite[4].img_data[temp + 3 - i];// couleur du texel
//					i++;
//				}
//			}
			if (test && side)
			{
				temp = (int)(texY) * data->sprite[1].size_line + (int)(texX) * 4;
				while (i < 4)
				{
					color[i] = data->sprite[1].img_data[temp + 3 - i];// couleur du texel
					i++;
				}
			}
			else if (!test && side)
//			if (side)
			{
				temp = (int)(texY) * data->sprite[2].size_line + (int)(texX) * 4;
				while (i < 4)
				{
					color[i] = data->sprite[2].img_data[temp + 3 - i];// couleur du texel
					i++;
				}
			}
			else
			{
				temp = (int)(texY) * data->sprite[0].size_line + (int)(texX) * 4;
				while (i < 4)
				{
					color[i] = data->sprite[0].img_data[temp + 3 - i];// couleur du texel
					i++;
				}
			}
			pos =   
				(int)y * data->image->size_line +
				(int)x * data->image->bits_per_pixel / 8;
			pos = data_len - pos;
			ft_put_pixel(data->image->img_data, color, pos);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->image->image, 0, 0);
	return (0);
}
