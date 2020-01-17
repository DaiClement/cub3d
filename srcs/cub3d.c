/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:11:35 by cdai              #+#    #+#             */
/*   Updated: 2020/01/14 11:23:10 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int av, char **ac)
{
	(void)ac;
	if (av == 1)
	{
		ft_putstr_fd("ERROR: cub3D needs at least 1 argument\n", 0);
		return (0);
	}
	else if (av >= 2)
	{
		ft_launch_game(ac[1]);
		return (0);
	}
}
