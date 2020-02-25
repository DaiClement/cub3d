/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:55:03 by cdai              #+#    #+#             */
/*   Updated: 2020/02/18 18:21:25 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_next_value(int nb, int sign, char digit)
{
	int	temp;

	temp = nb;
	if (sign == 1)
	{
		temp = nb * 10 + (digit - 48);
		if (temp < nb)
			return (2147483647);
		else
			return (temp);
	}
	else
	{
		temp = nb * 10 + (-digit + 48);
		if (temp > nb)
			return (-2147483648);
		else
			return (temp);
	}
}

int			ft_atoi(const char *str)
{
	int				result;
	int				sign;
	unsigned int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 0;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = ft_atoi_next_value(result, sign, str[i]);
		i++;
	}
	return (result);
}
