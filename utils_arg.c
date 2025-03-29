/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:47 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/27 10:39:46 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *str)
{
	ft_putstr_fd("Error:\t", STDERR_FILENO);
	if (!str)
		ft_putstr_fd("(undefined error)", STDERR_FILENO);
	else
		ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	arg_free(char **av, bool check)
{
	int	i;

	if (!check || !av)
		return ;
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

char	**arg_check(int ac, char **av)
{
	char	**array;

	if (ac == 1)
		exit (EXIT_FAILURE);
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		if (!array || !array[0])
			(arg_free(array, ac == 2), error_exit("empty array"));
	}
	else
		array = av + 1;
	return (array);
}
