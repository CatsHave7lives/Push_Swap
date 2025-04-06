/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:52:45 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/05 22:26:18 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_check(int ac, char **av)
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

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	av = build_stack(&stack_a, arg_check(ac, av), (ac == 2));
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->lower;
	}
	// if (!stack_sort(stack_a))
	// {
		
	// }
	return (0);
}
