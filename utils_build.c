/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:46:27 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/01 19:25:58 by aessaber         ###   ########.fr       */
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

static char	**append_to_array(char **av_current, int spot)
{
	char	**array;
	char	**av_replace;
	size_t	len;
	int		row;
	int		i;

	array = ft_split(av_current[spot], ' ');
	if (!array || !array[0])
		return (arg_free(array, true), NULL);
	len = ft_arraylen(av_current) + ft_arraylen(array) -1;
	av_replace = (char **)malloc(sizeof(char *) * (len +1));
	if (!av_replace)
		return (arg_free(array, true), NULL);
	row = 0;
	while (row < spot)
		av_replace[row] = ft_strdup(av_current[row++]);
	i = 0;
	while (array[i])
		av_replace[row++] = ft_strdup(array[i++]);
	spot++;
	while (av_current[spot])
		av_replace[row++] = ft_strdup(av_current[spot]);
	av_replace[row] = NULL;
	return (arg_free(array, true), av_replace);
}

static void	build_node(t_stack **stack_a, int value)
{
	t_stack	*node_current;
	t_stack	*node_add;

	if (!stack_a)
		return ;
	node_add = stack_metadata(value);
	if (!node_add)
		return ;
	if (!*stack_a)
		*stack_a = node_add;
	else
	{
		node_current = *stack_a;
		while (node_current->lower)
			node_current = node_current->lower;
		node_current->lower = node_add;
		node_add->upper = node_current;
	}
}

static void	value_validation(t_stack **stack_a, char **av, long value, bool ac_is_2)
{
	if (value < INT_MIN || value > INT_MAX)
		(stack_free(stack_a), arg_free(av, ac_is_2), error_exit());
	if (value_is_dup(stack_a, (int)value))
		(stack_free(stack_a), arg_free(av, ac_is_2), error_exit());
}

char	**build_stack(t_stack **stack_a, char **av, bool ac_is_2)
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
			if (ac_is_2)
				arg_free(default_av, true);
			ac_is_2 = true;
		}
		if (value_is_invalid(av[row]))
			(stack_free(stack_a), arg_free(av, ac_is_2), error_exit());
		value = ft_atol(av[row++]);
		value_validation(stack_a, av, value, ac_is_2);
		build_node(stack_a, (int)value);
	}
	return (av);
}
