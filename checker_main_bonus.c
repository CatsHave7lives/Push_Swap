/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:02:06 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/11 03:28:05 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static void	get_moves(t_stack **stack_a, t_stack **stack_b, bool ac2, char **av)
{
	char	*move;

	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		if (validate_move(move, stack_a, stack_b) == 1)
		{
			free(move);
			free_error(stack_a, av, ac2);
		}
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	free(move);
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
	get_moves(&stack_a, &stack_b, ac == 2, av);
	if (stack_is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if ((ac == 2) || (ac > 2 && has_space))
		free_arg(av, true);
	return (free_stack(&stack_a), EXIT_SUCCESS);
}
