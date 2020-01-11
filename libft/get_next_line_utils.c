/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:53:15 by cdai              #+#    #+#             */
/*   Updated: 2020/01/10 14:15:51 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_init(char **line, char **temp)
{
	if (!(*line = malloc(sizeof(**line))) ||
		!(*temp = malloc(sizeof(**temp))))
		return (0);
	**line = 0;
	**temp = 0;
	return (1);
}
