/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:38:31 by cdai              #+#    #+#             */
/*   Updated: 2020/02/07 19:45:13 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_put_case(char *img_data, int size_line, int bits_per_pixel, int i, int j, int case_size , int color[4])
{
	int 	k;
	int pos = 0;
	int h = 0;
	int w = 0;

			h = 0;
			while (h < case_size)
			{
				w = 0;
				while (w < case_size)
				{
					k = 0;
					while (k < 4)
					{
						pos =	i * case_size * size_line +
								j * case_size * bits_per_pixel / 8 +
								k +
								w * bits_per_pixel / 8 +
								h * size_line;
						img_data[pos] = (char)color[pos % 4];
						k++;
					}
					w++;
				}
				h++;
			}
}

int	ft_put_map_to_image(t_scene *scene, void *win_ptr, void *image)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*img_data;
	int		i;
	int 	j;
	int case_size = 64;
    int background_color[4] = {255, 255, 255, 0};
    int ceilling_color[4] = {255, 0, 0, 0};
    int floor_color[4] = {127, 127, 255, 195};
	int character_color[4] = {0, 0, 255, 0};

	i = 0;
	j = 0;
	img_data = mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);
	printf("test\n");
	while (i < 14)
	{
		j = 0;
		while (j < 29)
		{
			printf("%c", scene->map[i][j]);
			if (scene->map[i][j] == '1')
				ft_put_case(img_data, size_line, bits_per_pixel, i, j, case_size, floor_color);
			else if (scene->map[i][j] == '0')
				ft_put_case(img_data, size_line, bits_per_pixel, i, j, case_size, background_color);
			else if (scene->map[i][j] == '2')
				ft_put_case(img_data, size_line, bits_per_pixel, i, j, case_size, ceilling_color);
			else if (scene->map[i][j] == 'N')
				ft_put_case(img_data, size_line, bits_per_pixel, i, j, case_size, character_color);
			j++;
		}
		printf("\n");
		i++;
	}
	(void)scene;
	(void)win_ptr;
	return (0);
}
