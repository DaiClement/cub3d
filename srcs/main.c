/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:00:45 by cdai              #+#    #+#             */
/*   Updated: 2020/03/02 17:36:05 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int av, char **ac)
{
	if (av == 1)
		ft_putstr_fd("ERROR: cub3D needs at least 1 .cub argument.\n", 0);
	else if (av == 2)
		ft_launch_game(ac[1]);
	else
	{
		if (!ft_strncmp(ac[2], "-save", 6) || !ft_strncmp(ac[2], "--save", 7))
			ft_take_screenshot(ac[1]);
		else
			ft_print_error("Flag not recognized");
	}
	return (0);
}
