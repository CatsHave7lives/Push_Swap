/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_advanced.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:47:30 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/21 15:12:47 by aessaber         ###   ########.fr       */
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

char	**arg_check(int ac,char **av)
{
	if (ac == 1)
		exit (EXIT_SUCCESS);
}