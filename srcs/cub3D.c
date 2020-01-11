#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include "cub3D.h"

int main(int av, char **ac)
{
	(void)ac;
	if (av == 1)
	{
		ft_putstr_fd("ERROR: cub3D needs at least 1 argument\n", 0);
		return (0);
	}
	if (av >= 2)
	{
		if(ft_check_file_extention(ac[1]) != 0)
		{
			ft_putstr_fd("ERROR: file \"", 0);
			ft_putstr_fd(ac[1], 0);
			ft_putstr_fd("\" has wrong extention\n", 0);
		}
	}
}
