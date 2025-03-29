/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:07:24 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/27 10:53:26 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static bool	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	ft_isoverflow(size_t num, char c)
{
	return (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && (c - '0') > 7));
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
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(str[i]))
	{
		if (ft_isoverflow(num, str[i]))
			return (-(sign != -1));
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}
