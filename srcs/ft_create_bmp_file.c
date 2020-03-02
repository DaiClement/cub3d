/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bmp_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:54:04 by cdai              #+#    #+#             */
/*   Updated: 2020/03/02 17:35:22 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_file_n_image_header(t_game_data *data, int fd)
{
	int			temp;
	short int	short_temp;

	write(fd, "BM", 2);
	temp = data->scene.width * data->scene.height * 3 + 54;
	write(fd, &temp, sizeof(temp));
	temp = 0;
	write(fd, &temp, sizeof(temp));
	temp = 54;
	write(fd, &temp, sizeof(temp));
	temp = 40;
	write(fd, &temp, sizeof(temp));
	write(fd, &data->scene.width, sizeof(int));
	write(fd, &data->scene.height, sizeof(int));
	short_temp = 1;
	write(fd, &short_temp, sizeof(short_temp));
	short_temp = 32;
	write(fd, &short_temp, sizeof(short_temp));
	temp = 0;
	short_temp = -1;
	while (++short_temp < 6)
		write(fd, &temp, sizeof(temp));
}

int			ft_create_bmp_file(t_game_data *data)
{
	int	fd;
	int	i;

	if ((fd = open("cub3d-screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC,
		S_IRWXU)) == -1)
		return (ft_print_error("Open fail"));
	ft_set_file_n_image_header(data, fd);
	i = 0;
	while (i < data->scene.height)
	{
		write(fd, data->working_img.img_data +
		((data->scene.height - i - 1) * data->scene.width * 4),
		data->scene.width * 4);
		i++;
	}
	close(fd);
	return (1);
}
