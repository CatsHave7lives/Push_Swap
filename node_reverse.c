/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:38:14 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/15 21:55:21 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	node_reverse(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;
	t_stack	*penult;

	if (!stack || !*stack || !(*stack)->lower)
		return (false);
	top = *stack;
	bottom = stack_bottom(top);
	penult = bottom->upper;
	top->upper = bottom;
	bottom->lower = top;
	bottom->upper = NULL;
	penult->lower = NULL;
	*stack = bottom;
	return (true);
}

void	rra(t_stack **stack_a)
{
	if (node_reverse(stack_a))
		write(1, "rra\n", 3);
}

void	rrb(t_stack **stack_b)
{
	if (node_reverse(stack_b))
		write(1, "rrb\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	bool	reverse_a;
	bool	reverse_b;

	reverse_a = node_reverse(stack_a);
	reverse_b = node_reverse(stack_b);
	if (reverse_a || reverse_b)
		write(1, "rrr\n", 3);
}
