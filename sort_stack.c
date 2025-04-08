/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 06:38:21 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/08 21:08:56 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lowest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*n_i;
	int		value_lowest;
	t_stack	*n_lowest;

	n_i = *stack_a;
	value_lowest = INT_MAX;
	while (n_i)
	{
		if (n_i->value <= value_lowest)
		{
			value_lowest = n_i->value;
			n_lowest = n_i;
		}
		n_i = n_i->lower;
	}
	while (*stack_a != n_lowest)
	{
		if (n_lowest->above_mid)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->lower->value)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*n_i;
	int		value_highest;
	t_stack	*node_highest;

	n_i = *stack_a;
	value_highest = INT_MIN;
	while (n_i)
	{
		if (n_i->value >= value_highest)
		{
			value_highest = n_i->value;
			node_highest = n_i;
		}
		n_i = n_i->lower;
	}
	if (*stack_a == node_highest)
		ra(stack_a);
	else if ((*stack_a)->lower == node_highest)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->lower->value)
		sa(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
		(update_stack(stack_a, stack_b), push_lowest(stack_a, stack_b));
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
