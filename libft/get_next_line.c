/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:11:10 by cdai              #+#    #+#             */
/*   Updated: 2020/01/10 14:15:22 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strcut(char **buffer)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while ((*buffer)[++i])
	{
		if ((*buffer)[i] == '\n')
		{
			i++;
			while ((*buffer)[i + (++j)])
				(*buffer)[j] = (*buffer)[i + j];
			(*buffer)[j] = 0;
			return (1);
		}
	}
	free(*buffer);
	*buffer = 0;
	return (2);
}

static char	*ft_strjoin_mix(char *buffer, char **line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((*line)[i])
		i++;
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if (!(temp = malloc(sizeof(*temp) * (i + j + 1))))
		return (0);
	j = -1;
	while ((*line)[++j])
		temp[j] = (*line)[j];
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		temp[i + j] = buffer[j];
		j++;
	}
	temp[i + j] = 0;
	free(*line);
	return (temp);
}

static int	ft_error_free(char **buffer, char **temp)
{
	if (*buffer)
		free(*buffer);
	*buffer = 0;
	if (*temp)
		free(*temp);
	*temp = 0;
	return (-1);
}

static int	ft_create_temp(int fd, char **temp, char **buffer)
{
	int			size;

	if (fd < 0 || !(*buffer = malloc(sizeof(**buffer) * (BUFFER_SIZE + 1)))
		|| (size = read(fd, *buffer, BUFFER_SIZE)) < 0)
		return (ft_error_free(buffer, temp));
	(*buffer)[size] = 0;
	if (size != BUFFER_SIZE)
	{
		if (!(*temp = ft_strjoin_mix(*buffer, temp)))
			return (ft_error_free(buffer, temp));
		size = ft_strcut(buffer);
		if (size == 2)
			return (0);
		else
			return (1);
	}
	return (2);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[1024] = {NULL};
	char		*temp;
	int			line_finished;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!ft_init(line, &temp))
		return (-1);
	line_finished = 2;
	while (line_finished == 2)
	{
		if (!buffer[fd])
			if ((line_finished = ft_create_temp(fd, &temp, &buffer[fd])) == -1)
				return (-1);
		if (line_finished == 2)
		{
			if (!(temp = ft_strjoin_mix(buffer[fd], &temp)))
				return (ft_error_free(&buffer[fd], &temp));
			line_finished = ft_strcut(&buffer[fd]);
		}
	}
	free(*line);
	*line = temp;
	return (line_finished);
}
