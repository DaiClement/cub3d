/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:11:35 by cdai              #+#    #+#             */
/*   Updated: 2020/02/07 09:42:25 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_main_arg(int av, char **ac)
{
	int	i;

	i = 0;
	while (i < av)
	{
		if (ft_strncmp(ac[i], "--save", 6))
			return (1);
		i++;
	}
	return (0);
}

int			main(int av, char **ac)
{
	int	save;

	save = ft_check_main_arg(av, ac);
	if (av == 1)
	{
		ft_putstr_fd("ERROR: cub3D needs at least 1 argument\n", 0);
		return (0);
	}
	else if (av >= 2)
	{
		ft_launch_game(ac[1]);
//		while(1);
		return (0);
	}
}
