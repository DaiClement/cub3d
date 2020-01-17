/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi_max_min.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:27:28 by cdai              #+#    #+#             */
/*   Updated: 2020/01/17 11:32:41 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_atoi_max_min(char *nb)
{
	int i;
	int negative;

	i = 0;
	negative = 0;
	if (nb[i] == '-')
	{
		negative = 1;
		i++;
	}
	while (ft_isdigit(nb[i]))
		i++;
	if ((negative && (i > 12 || i < 2)) || (!negative && (i > 11 || i < 1)))
		return (0);
	else if (!(nb[i] == 44 || nb[i] == 0))
		return (0);
	printf("%d\n", nb[i]);
	return (1);
}
