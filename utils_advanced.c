/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:47:30 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/05 09:22:23 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	num;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(str[i]))
	{
		if (num > 922337203685477580
			|| (num == 922337203685477580 && (str[i] - '0') > 7))
			return (ft_isoverflowed(sign));
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}