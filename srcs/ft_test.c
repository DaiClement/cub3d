/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:13:12 by cdai              #+#    #+#             */
/*   Updated: 2020/02/07 16:45:51 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void ft_put_pixel(char *img_data, int color[4], int pos)
{
    int k;

    k = 0;
    while (k < 4)
    {
        img_data[pos - k] = color[k];
        k++;
    }
}

int ft_test(t_game_data *data)
{
	// pos_x et pos_y sont les positions de la camera/joueur
	double pos_x = data->camera->pos_x;
	double pos_y = data->camera->pos_y;
	// angle est l'angle du regard du centre de l'ecran
	double angle = data->camera->angle;
	printf("angle :%f\n",angle);

	//x et y sont des compteurs
	int x = 0;
	int y = 0;

	// on cherche le modulo de 2 * M_PI;
	angle = ft_modulo_two_pi(angle);
	// plane_dist est la distance entre le joueur et le centre du plan camera
	double plane_dist = (data->scene->resolution[0] / 2) / tan(M_PI / 6);

	// screen->width = data->scene->resolution[0]
	// screen->height = data->scene->resolution[1]
	double step_angle = (M_PI / 3) / data->scene->resolution[0];
	printf("step_angle :%f\n", step_angle);

	// ray_angle est l'angle du rayon en cours par rapport au centre de la camera
	double ray_angle = M_PI / 6 + step_angle;

	// norm_ray_angle est l'angle par rapport a angle 0
	double norm_ray_angle = angle + ray_angle;

	// valeur de deplacement
	int step_x = 0;
	int step_y = 0;

	// rayX et rayY sont les distances PRECISES du rayon dans la map en 2D depuis la camera
	double dist_ray_x = 0;
	double dist_ray_y = 0;

	// delta_ray_x et delta_ray_y sont les distances entre 2 cases avant de toucher une paroi d'une case
	double delta_ray_x = 0;
	double delta_ray_y = 0;

	// side pour savoir l'orientation N/S ou W/E
	int side = 0;

	// distance de l'hypothenuse
	double dist_hypo = 0;

	// on balaye l'ecran de gauche a droite
	while (x < data->scene->resolution[0])
	{
		// on trouve le rayon en cours. Je decremente 
		ray_angle -= step_angle;
		norm_ray_angle = angle + ray_angle;
		ray_angle = fabs(ray_angle);
		norm_ray_angle = ft_modulo_two_pi(norm_ray_angle);
		// on cherche dans quelle direction on va avec les rayons
		// calcul du 'pas'
		if (norm_ray_angle >= M_PI / 2 && norm_ray_angle < M_PI * 1.5)
		{
			step_x = -1;
			delta_ray_x = fabs(tan(ray_angle) * 1);
		}
		else
		{
			step_x = 1;
			delta_ray_x = fabs(1 / tan(ray_angle));
		}
		if (norm_ray_angle >= 0 && norm_ray_angle < M_PI)
		{
			step_y = -1;
			delta_ray_y = fabs(1 / tan(ray_angle));
		}
		else
		{
			step_y = 1;
			delta_ray_y = fabs(tan(ray_angle) * 1);
		}
		// pos_ray_x et pos_ray_y sont les positions du rayon dans la map en 2D. On demarre la ou est la camera
		int pos_ray_x = (int)pos_x;
		int pos_ray_y = (int)pos_y;

		// distance avec la premiere limite d'une casse 
		dist_ray_x = fabs(tan(ray_angle) * (pos_x - pos_ray_x));
		dist_ray_y = fabs((pos_y - pos_ray_y) / tan(ray_angle));


		//hit est juste un booleen si le rayon touche un mur ('1')
		int hit = 0;
		while (!hit)
		{
			if (dist_ray_x < dist_ray_y)
			{
				dist_ray_x += delta_ray_x;
				pos_ray_x += step_y;
				side = 1;
			}
			else
			{
				dist_ray_y += delta_ray_x;
				pos_ray_y += step_x;
				side = 0;
			}
			if (data->scene->map[pos_ray_y][pos_ray_x] == '1')
				hit = 1;
		}
		// pos servira pour l'emplacement du pixel
		int pos;
		
		// on verifie si c'est un mur N/S ou un mur W/E
		if (side)
			dist_hypo = (dist_ray_x - delta_ray_x * ((1 - step_x) / 2) / sin(ray_angle));
		else
			dist_hypo = (dist_ray_y - delta_ray_y * ((1 - step_y) / 2) / cos(ray_angle));

		// start est le depart du mur par rapport au sol
		// on fera le miroir pour le plafond
		double start = (data->scene->resolution[1] / 2) + (32 / dist_hypo);// 32 = hauteur du mur
		if (start >= data->scene->resolution[1])
			start = data->scene->resolution[1] - 1;

		y = start;
		// ici on balaye l'ecran de haut en bas depuis le centre pour le sol et de bas en haut pour le plafond
        while (y < data->scene->resolution[1])
        {
            pos =
                4 *
                data->scene->resolution[0] *
                data->scene->resolution[1] -
                1 -
                (int)y * data->image->size_line -
                (int)x * data->image->bits_per_pixel / 8;
            ft_put_pixel(data->image->img_data, data->scene->floor, pos);
            pos =
                4 *
                data->scene->resolution[0] *
                data->scene->resolution[1] -
                1 -
                (int)(data->scene->resolution[1]-y-1) * data->image->size_line -
                (int)x * data->image->bits_per_pixel / 8;
            ft_put_pixel(data->image->img_data, data->scene->ceilling, pos);
            y++;
        }
		x++;
		printf("delta_ray_x :%f, delta_ray_y :%f\n", delta_ray_x, delta_ray_y);
		printf("pos_ray_x :%d, pos_ray_y :%d\n", pos_ray_x, pos_ray_y);
//		printf("pos_x :%f, pos_y :%f\n", pos_x, pos_y);
//		printf("step_x :%d, step_y :%d\n", step_x, step_y);
		printf("dist_ray: %f, %f\n", dist_ray_x, dist_ray_y);
		printf("%f\n", ray_angle);
	    mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->image->image, 0, 0);
	}
	printf("step_x :%d, step_y :%d\n", step_x, step_y);
	return 0;
}
