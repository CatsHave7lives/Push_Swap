/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:21:22 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 02:43:24 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rank(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *a_i;

	while(stack_size(*stack_a) > 3)
	{
		a_i = *stack_a;
		update_stack(stack_a, stack_b);
		if (a_i->rank <= stack_size(*stack_a) / 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
}

static t_stack *node_is_best(t_stack **stack_b)
{
	t_stack	*b_i;

	if (!stack_b || !*stack_b)
		return (NULL);
	b_i = *stack_b;
	while (b_i)
	{
		if (b_i->is_best)
			return (b_i);
		b_i = b_i->lower;
	}
	return (NULL);
}

static void best_to_top(t_stack **stack, t_stack *n_is_best, bool is_a)
{
	if (!stack || !*stack)
		return ;
	while (*stack != n_is_best)
	{
		if (is_a)
		{
			if (n_is_best->above_mid)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (n_is_best->above_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_is_best;

	b_is_best = node_is_best(stack_b);
	if (!b_is_best)
		return ;
	if (b_is_best->above_mid && b_is_best->a_target->above_mid)
	{
		while (*stack_a != b_is_best->a_target && *stack_b != b_is_best)
			rr(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	else if (!b_is_best->above_mid && !b_is_best->a_target->above_mid)
	{
		while (*stack_a != b_is_best->a_target && *stack_b != b_is_best)
			rr(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	best_to_top(stack_a, b_is_best->a_target, true);
	best_to_top(stack_b, b_is_best, false);
	pa(stack_a, stack_b);
}
