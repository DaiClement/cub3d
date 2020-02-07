/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo_two_pi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:42:38 by cdai              #+#    #+#             */
/*   Updated: 2020/02/07 10:16:40 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_modulo_two_pi(double nb)
{
	const double	circle = 2 * M_PI;
	if (nb < 0)
		while (nb < 0)
			nb += circle;
	else
		while (nb >= circle)
			nb -= circle;
	return (nb);
}
