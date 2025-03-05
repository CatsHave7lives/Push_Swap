/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:47 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/05 10:46:46 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_overflowed(int sign)
{
	if (sign == -1)
	{
		return (0);
	}
	return (-1);
}
