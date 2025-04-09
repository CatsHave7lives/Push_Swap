/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:10:07 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 03:36:11 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_index(t_stack **stack)
{
	int		index;
	t_stack	*n_i;

	if (!stack || !*stack)
		return ;
	index = 0;
	n_i = *stack;
	while (n_i)
	{
		n_i->index = index;
		index++;
		n_i = n_i->lower;
	}
}

static void	update_rank(t_stack **stack)
{
	int		rank;
	t_stack	*n_i;
	t_stack	*n_j;

	if (!stack || !*stack)
		return ;
	n_i = *stack;
	while (n_i)
	{
		rank = 0;
		n_j = *stack;
		while (n_j)
		{
			rank += (n_i->value > n_j->value);
			n_j = n_j->lower;
		}
		n_i->rank = rank;
		n_i = n_i->lower;
	}
}

static void	update_above_mid(t_stack **stack)
{
	int		size_half;
	t_stack	*n_i;

	if (!stack || !*stack)
		return ;
	size_half = stack_size(*stack) / 2;
	n_i = *stack;
	while (n_i)
	{
		n_i->above_mid = (n_i->index <= size_half);
		n_i = n_i->lower;
	}
}

static void	update_is_best(t_stack **stack_b)
{
	t_stack	*b_i;
	int		move_cost;

	if (!stack_b || !*stack_b)
		return ;
	b_i = *stack_b;
	move_cost = b_i->move_cost;
	while (b_i)
	{
		if (move_cost > b_i->move_cost)
			move_cost = b_i->move_cost;
		b_i = b_i->lower;
	}
	b_i = *stack_b;
	while (b_i)
	{
		b_i->is_best = (move_cost == b_i->move_cost);
		b_i = b_i->lower;
	}
}

void	update_stack(t_stack **stack_a, t_stack **stack_b)
{
	(update_index(stack_a), update_index(stack_b));
	(update_rank(stack_a), update_rank(stack_b));
	(update_above_mid(stack_a), update_above_mid(stack_b));
	update_target(stack_a, stack_b);
	update_move_cost(stack_a, stack_b);
	update_is_best(stack_b);
}
