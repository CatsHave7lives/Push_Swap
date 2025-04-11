/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:19:27 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 22:53:52 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	row_has_space(char *str)
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

static bool	value_is_invalid(char *str)
{
	int	i;

	if (!ft_issign(str[0]) && !ft_isdigit(str[0]))
		return (true);
	if (ft_issign(str[0]) && !(ft_isdigit(str[1])))
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

static void	value_validation(t_stack **stack_a, char **av, int value, bool ac2)
{
	t_stack	*node;

	node = *stack_a;
	while (node)
	{
		if (node->value == value)
			free_error(stack_a, av, ac2);
		node = node->lower;
	}
}

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
				free_error(stack_a, av, ac2);
			if (ac2)
				free_arg(default_av, true);
			ac2 = true;
		}
		if (value_is_invalid(av[row]))
			free_error(stack_a, av, ac2);
		value = ft_atol(av[row++]);
		if (value > INT_MAX || value < INT_MIN)
			free_error(stack_a, av, ac2);
		(value_validation(stack_a, av, value, ac2), build_node(stack_a, value));
	}
	return (av);
}
