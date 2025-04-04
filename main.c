/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:52:45 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/04 21:31:15 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	av = build_stack(&stack_a, arg_check(ac, av), (ac == 2));
	// if (!stack_sort(stack_a))
	// {
		
	// }
	return (0);
}
