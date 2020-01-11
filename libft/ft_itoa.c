/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:47:50 by cdai              #+#    #+#             */
/*   Updated: 2019/11/08 17:06:21 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_pow10(int n, int *count)
{
	if (n < 0)
	{
		n = -n;
		*count = *count + 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		*count = *count + 1;
	}
}

static void	ft_sub_itoa_recursive(int n, char *result, int count)
{
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	if (n < 10)
		result[count - 1] = n + 48;
	else
	{
		ft_sub_itoa_recursive(n / 10, result, count - 1);
		ft_sub_itoa_recursive(n % 10, result, count);
	}
}

static char	*ft_return_int_min(void)
{
	char		*result;
	const char	int_min[] = "-2147483648";
	int			i;

	i = 0;
	if (!(result = malloc(sizeof(*result) * 12)))
		return (0);
	while (int_min[i])
	{
		result[i] = int_min[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		count;

	count = 1;
	result = 0;
	if (n == -2147483648)
	{
		result = ft_return_int_min();
		return (result);
	}
	ft_count_pow10(n, &count);
	if (!(result = malloc(sizeof(*result) * (count + 1))))
		return (0);
	ft_sub_itoa_recursive(n, result, count);
	result[count] = 0;
	return (result);
}
