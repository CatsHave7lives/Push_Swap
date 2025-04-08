/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:04:25 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 00:39:04 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_cost(t_stack *b_i, int a_move_cost, int b_move_cost)
{
	int	move_cost;
	if (b_i->above_mid == b_i->a_target->above_mid)
	{
		if (a_move_cost > b_move_cost)
			move_cost = a_move_cost;
		else
			move_cost = b_move_cost;
	}
	else
		move_cost = a_move_cost + b_move_cost;
	return (move_cost);
}

void	update_move_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_i;
	int		a_move_cost;
	int		a_size;
	int		b_move_cost;
	int		b_size;

	if(!stack_b || !*stack_b)
		return ;
	b_i = *stack_b;
	a_size = stack_size(*stack_a);
	b_size = stack_size(*stack_b);
	while (b_i)
	{
		if (b_i->a_target->above_mid)
			a_move_cost = b_i->a_target->index;
		else
			a_move_cost = a_size - b_i->a_target->index;
		if (b_i->above_mid)
			b_move_cost = b_i->index;
		else
			b_move_cost = b_size - b_i->index;
		b_i->move_cost = total_cost(b_i, a_move_cost, b_move_cost);
		b_i = b_i->lower;
	}
}

static t_stack	*closest_greater(t_stack **stack_a, int b_value)
{
	t_stack	*a_i;
	t_stack	*b_target;
	int		b_target_value;

	a_i = *stack_a;
	b_target = NULL;
	b_target_value = INT_MAX;
	while (a_i)
	{
		if (b_value < a_i->value && a_i->value < b_target_value)
		{
			b_target_value = a_i->value;
			b_target = a_i;
		}
		a_i = a_i->lower;
	}
	if (b_target_value == INT_MAX)
		b_target = stack_value_lowest(*stack_a);
	return (b_target);
}

void	update_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_i;

	if (!stack_b || !*stack_b)
		return ;
	b_i = *stack_b;
	while (b_i)
	{
		b_i->a_target = closest_greater(stack_a, b_i->value);
		b_i = b_i->lower;
	}
}
