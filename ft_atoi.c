/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:07:24 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/24 04:07:25 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_is_overflowed(int sign)
{
	if (sign == -1)
	{
		return (0);
	}
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	num;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(str[i]))
	{
		if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && (str[i] - '0') > 7))
			return (ft_is_overflowed(sign));
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}