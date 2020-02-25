/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi_max_min.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:15:55 by cdai              #+#    #+#             */
/*   Updated: 2020/02/17 11:06:03 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_atoi_max_min(char *nb)
{
	int	i;
	int	negative;
	int	nb_zero;

	i = 0;
	negative = 0;
	nb_zero = 0;
	if (nb[0] == '-')
	{
		negative = 1;
		i++;
	}
	while (nb[nb_zero + i] == '0')
		nb_zero++;
	while (ft_isdigit(nb[nb_zero + i]))
		i++;
	if ((negative && (i > 12 || (!nb_zero && i < 2))) ||
	(!negative && (i > 11 || (!nb_zero && !i))))
		return (0);
	return (1);
}
