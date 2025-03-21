/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:37 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/16 17:23:32 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	node_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !*stack || !(*stack)->lower)
		return (false);
	first = *stack;
	second = first->lower;
	third = second->lower;
	first->lower = third;
	first->upper = second;
	second->lower = first;
	second->upper = NULL;
	if (third)
		third->upper = first;
	*stack = second;
	return (true);
}

void	sa(t_stack **stack_a)
{
	if (node_swap(stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	if (node_swap(stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	bool	swap_a;
	bool	swap_b;

	swap_a = node_swap(stack_a);
	swap_b = node_swap(stack_b);
	if (swap_a || swap_b)
		write(1, "ss\n", 3);
}
