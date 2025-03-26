/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:47 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/26 02:00:06 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_check(int ac,char **av)
{
	char	**array;

	if (ac == 1)
		exit (EXIT_FAILURE);
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		if (!array || !array[0])
			(free_arg(array, ac == 2), print_error());
	}
	else
		array = av + 1;
	return (array);
}
