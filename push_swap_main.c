/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:52:45 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/11 03:24:16 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	av_has_space(char **av)
{
	int		row;
	int		col;

	row = 0;
	while (av[row])
	{
		col = 0;
		while (av[row][col])
		{
			if (av[row][col] == ' ')
				return (true);
			col++;
		}
		row++;
	}
	return (false);
}

static char	**arg_check(int ac, char **av)
{
	char	**array;

	if (ac == 1)
		exit (EXIT_FAILURE);
	if (ac > 2)
		return (av + 1);
	array = ft_split(av[1], ' ');
	if (!array || !array[0])
		(free_arg(array, ac == 2), error_exit());
	return (array);
}

static bool	stack_is_sorted(t_stack *stack_a)
{
	t_stack	*node;

	if (!stack_a)
		return (false);
	node = stack_a;
	while (node->lower)
	{
		if (node->value > node->lower->value)
			return (false);
		node = node->lower;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	bool	has_space;

	stack_a = NULL;
	stack_b = NULL;
	has_space = av_has_space(av);
	av = build_stack(&stack_a, arg_check(ac, av), (ac == 2));
	if (!stack_is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sort_two(&stack_a);
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
			sort_five(&stack_a, &stack_b);
		else
			sort_stack(&stack_a, &stack_b);
	}
	if ((ac == 2) || (ac > 2 && has_space))
		free_arg(av, true);
	return (free_stack(&stack_a), EXIT_SUCCESS);
}
