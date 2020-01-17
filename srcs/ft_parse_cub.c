/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:15:58 by cdai              #+#    #+#             */
/*   Updated: 2020/01/11 18:54:54 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scene	*ft_parse_cub(const char *filename)
{
	t_scene	*scene;

	if (ft_check_file_extention(filename, ".cub") == 0)
		return (NULL);
	if (!(scene = ft_fullfill_scene(filename)))
		return (NULL);
	return (scene);
}
