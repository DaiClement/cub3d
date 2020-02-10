/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:02:58 by cdai              #+#    #+#             */
/*   Updated: 2020/02/10 17:13:49 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_handle_image(t_game_data *data)
{
	int init_pos = 0;
	int pos;
	// taille de la projection
	//	double w = data->scene->resolution[0];
	//	double h = data->scene->resolution[1];
	t_sprite	*temp_sprite = 0;
	double x = 0;
	double y = 0;

	ft_handle_mouvement(data);	
	char color[4];
		double cameraX;
		double rayDirX;
		double rayDirY;
		int mapX;
		int mapY;
		double sideDistX;
		double sideDistY;
		double deltaDistX;
		double deltaDistY;
		int stepX;
		int stepY;
		int hit;
		int side;
		double perpWallDist;
		//calcule le vecteur de direction et la longueur entre deux segments
	while (x < data->scene->resolution[0])
	{
		//Position de départ et data->camera->direction du rayon
		cameraX = (2*x/data->scene->resolution[0])-1;// position de la colonne par rapport au centre de l’écran
//		double rayPosX = data->camera->pos_x;// position de départ du rayon sur X
//		double rayPosY = data->camera->pos_y;// position de départ du rayon sur Y
		rayDirX = data->camera->dir_x + data->camera->plane_x * cameraX;// data->camera->direction du rayon sur X
		rayDirY = data->camera->dir_y + data->camera->plane_y * cameraX;// data->camera->direction du rayon sur Y
		// sur quelle case est la caméra
		mapX = data->camera->pos_x;
		mapY = data->camera->pos_y;
		// longueur du rayon
		// sideDistX = 0;
		// sideDistY = 0;
		// longueur du rayon entre chaque intersection
		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		// data->camera->direction du vecteur sur X et Y (+1 ou -1)
		// int stepX = 0;
		// int stepY = 0;
		hit = 0;//le rayon touche un mur ou pas
		//int side = 0;//quelle orientation à le mur (nord/sud ou est/ouest) dans la map 
		//double perpWallDist = 0;// distance corrigée du rayon
		//calcule le vecteur de direction et la longueur entre deux segments
		if (rayDirX < 0)
		{
			stepX = -1;// vecteur de direction
			sideDistX = (data->camera->pos_x - mapX) * deltaDistX;// distance
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->camera->pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->camera->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->camera->pos_y) * deltaDistY;
		}
		// tant que le rayon ne rencontre pas de mur
		while (hit == 0)
		{
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
				hit=1;// stoppe la boucle 
			else if (data->scene->map[mapY][mapX] == '2')
			{
				temp_sprite = (t_sprite*)ft_calloc(1, sizeof(*temp_sprite));
				temp_sprite->x = mapX + 0.5;
				temp_sprite->y = mapY + 0.5;
				if (!data->sprite_list)
				{
					data->sprite_list = ft_lstnew(temp_sprite);
					(data->nb_sprite)++;
				}
				else
				{
					ft_lstadd_front(&data->sprite_list, ft_lstnew(temp_sprite));
					(data->nb_sprite)++;
				}
			}
		}
		// Calcule la distance corrigée pour la projection
		if (side > 1)
			perpWallDist = fabs((mapX - data->camera->pos_x + (1 - stepX) / 2) / rayDirX);
		else
			perpWallDist = fabs((mapY - data->camera->pos_y + (1 - stepY) / 2) / rayDirY);



		//Calcule la hauteur de la ligne à tracer
		double hauteurLigne = fabs(data->scene->resolution[1] / perpWallDist);
		//Calcule les pixels max haut et max bas de la colonne à tracer
		int drawStart = (-hauteurLigne / 2 + data->scene->resolution[1] / 2);
		int drawEnd = (hauteurLigne / 2 + data->scene->resolution[1] / 2);
		// limite les zones de tracé à l'écran uniquement
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= data->scene->resolution[1])
			drawEnd = data->scene->resolution[1]-1;
		// référence de la texture (-1 pour utiliser le 0 du tableau de textures)
		double wallX;// la colonne exacte touchée transposée sur X
		//  si le mur est orienté est/ouest (sur Y)
		if (side < 2)
			wallX = data->camera->pos_x + ((mapY - data->camera->pos_y + (1 - stepY) / 2) / rayDirY) * rayDirX;
		else
			wallX = data->camera->pos_y + ((mapX - data->camera->pos_x + (1 - stepX) / 2) / rayDirX) * rayDirY;
		wallX -= floor(wallX);// arrondis à l’inférieur 
		// coordonnée x de la colonne dans la texture
		double texX = (wallX * data->sprite[0].width);
		texX = data->sprite[0].width - texX - 1;
		y = drawStart;
		while (y < data->scene->resolution[1])
		{
			init_pos =
				data->scene->resolution[0] * data->scene->resolution[1] * 4 -
				1 - x * data->image->bits_per_pixel / 8;
			if (y < drawEnd)
			{
				double texY = (y * 2 - data->scene->resolution[1] + hauteurLigne) * (data->sprite[0].height/2)/hauteurLigne;// coordonnée Y du texel 
				int temp;
				temp = floor(texY) * data->sprite[side].size_line + floor(texX) * 4;
				pos =   
					init_pos -
					y * data->image->size_line;
				ft_put_pixel(data->image->img_data, &data->sprite[side].img_data[temp], pos);
			}
			else
			{
				pos =   
					init_pos -
					y * data->image->size_line;
				int i = 0;
//				while (i < 4)
//				{
//					color[i] = data->scene->floor[3 - i];// couleur du texel
//					i++;
//				}
				ft_put_pixel(data->image->img_data, data->scene->floor, pos);
				pos =
					init_pos -
					(data->scene->resolution[1]-y-1) * data->image->size_line;
//				i = 0;
//				while (i < 4)
//				{
//					color[i] = data->scene->ceilling[3 - i];// couleur du texel
//					i++;
//				}
//				ft_put_pixel(data->image->img_data, color, pos);
				ft_put_pixel(data->image->img_data, data->scene->ceilling, pos);
			}
			y++;
		}
		ft_handle_sprite(data, perpWallDist, x);
		x++;
		while (data->sprite_list)
		{
			free(data->sprite_list->content);
			free(data->sprite_list);
			data->sprite_list = data->sprite_list->next;
		}
		data->nb_sprite = 0;
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->image->image, 0, 0);
	return (0);
}
