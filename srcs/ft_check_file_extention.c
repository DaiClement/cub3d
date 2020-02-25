/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extention.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:18:38 by cdai              #+#    #+#             */
/*   Updated: 2020/02/24 11:59:16 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file_extention(char *filename, char *extention)
{
	int filename_len;
	int extention_len;

	filename_len = ft_strlen(filename);
	extention_len = ft_strlen(extention);
	if (filename_len < 5)
		return (0);
	else if (ft_strncmp(filename + filename_len - extention_len,
		extention, extention_len + 1))
		return (0);
	return (1);
}
