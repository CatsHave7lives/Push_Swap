/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:46:27 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/30 18:11:23 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_arraylen(char **array)
{
	size_t	row;

	if (!array)
		return (0);
	row = 0;
	while (array[row])
		row++;
	return (row);
}

static char	**append_to_array(char **current_av, int spot)
{
	char	**array;
	char	**replacement_av;
	size_t	len;
	int		row;
	int		i;

	array = ft_split(current_av[spot], ' ');
	if (!array || !array[0])
		return (arg_free(array, true), NULL);
	len = ft_arraylen(current_av) + ft_arraylen(array) -1;
	replacement_av = (char **)malloc(sizeof(char *) * (len +1));
	if (!replacement_av)
		return (arg_free(array, true), NULL);
	row = 0;
	while (row < spot)
		replacement_av[row] = ft_strdup(current_av[row++]);
	i = 0;
	while (array[i])
		replacement_av[row++] = ft_strdup(array[i++]);
	spot++;
	while (current_av[spot])
		replacement_av[row++] = ft_strdup(current_av[spot]);
	replacement_av[row] = NULL;
	return (arg_free(array, true), replacement_av);
}

void	

char	**build_stack(t_stack **stack_a, char **av, bool ac2)
{
	int		row;
	char	**default_av;
	long	value;

	row = 0;
	while (av[row])
	{
		if (row_has_space(av[row]))
		{
			default_av = av;
			av = append_to_array(av, row);
			if (!av || !av[0])
				(stack_free(stack_a), arg_free(av, true), error_exit());
			if (ac2)
				arg_free(default_av, true);
			ac2 = true;
		}
		if (value_is_invalid(av[row]))
			(stack_free(stack_a), arg_free(av, ac2), error_exit());
		value = ft_atol(av[row++]);
		if (value < INT_MIN || value > INT_MAX)
			(stack_free(stack_a), arg_free(av, ac2), error_exit());
		if (value_is_dup(stack_a, (int)value))
			(stack_free(stack_a), arg_free(av, ac2), error_exit());
		
	}
	return (av);
}
