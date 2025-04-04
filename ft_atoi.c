/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:07:24 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/04 18:53:56 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	value_is_invalid(char *str)
{
	int	i;

	if (!ft_issign(str[0]) && !ft_isdigit(str[0]))
		return (true);
	if (ft_issign(str[0]) && !ft_isdigit(str[1]))
		return (true);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	value_is_dup(t_stack **stack, int value)
{
	t_stack	*node;

	if (!stack || !*stack)
		return (false);
	node = *stack;
	while (node)
	{
		if (node->value == value)
			return (true);
		node = node->lower;
	}
	return (false);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	num;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
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
		// if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && (str[i] - '0') > 7))
		// 	return (-(sign != -1));
		if (num > INT_MAX || (num * sign) < INT_MIN)
			return (num * sign);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((num * sign));
}
