/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:47 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/04 17:59:41 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	(ft_putstr_fd("Error\n", STDERR_FILENO), exit(EXIT_FAILURE));
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
			(arg_free(array, ac == 2), error_exit());
	}
	else
		array = av + 1;
	return (array);
}

bool	row_has_space(char *str)
{
	int	col;

	col = 0;
	while (str[col])
	{
		if (str[col] == ' ')
			return (true);
		col++;
	}
	return (false);
}

bool	arg_has_space(char **av)
{
	int	row;

	row = 0;
	while (av[row])
	{
		if (row_has_space(av[row]))
			return (true);
		row++;
	}
	return (false);
}
