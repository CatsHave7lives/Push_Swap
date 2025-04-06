/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:07:24 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/05 20:52:51 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	num;

	i = 0;
	while (str[i] == ' ')
		i++;
	sign = 1;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(str[i]))
	{
		if (num > INT_MAX || (num * sign) < INT_MIN)
			return (num * sign);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((num * sign));
}
