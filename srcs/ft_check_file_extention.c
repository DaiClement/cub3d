/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extention.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:24:51 by cdai              #+#    #+#             */
/*   Updated: 2020/01/10 17:42:43 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_file_extention(const char *filename)
{
	int len;
	int i;

	len = ft_strlen(filename);
	i = 0;
	return ft_strncmp(filename+len-4, ".cub", 4);
}
