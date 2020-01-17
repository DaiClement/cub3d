/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extention.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:24:51 by cdai              #+#    #+#             */
/*   Updated: 2020/01/11 10:52:39 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_file_extention(const char *filename, const char *extention)
{
	int filename_len;
	int extention_len;

	filename_len = ft_strlen(filename);
	extention_len = ft_strlen(extention);
	if (filename_len <= 4)
	{
		ft_putstr_fd("ERROR: scene filename too short", 0);
		return (0);
	}
	else if (ft_strncmp(filename + filename_len - extention_len,
		extention, extention_len))
	{
		ft_putstr_fd("ERROR: file \"", 0);
		ft_putstr_fd((char*)filename, 0);
		ft_putstr_fd("\" has wrong file extention\n", 0);
		return (0);
	}
	return (1);
}
