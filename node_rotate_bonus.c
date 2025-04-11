/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:38:14 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 22:54:18 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	node_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*second;
	t_stack	*bottom;

	if (!stack || !*stack || !(*stack)->lower)
		return (false);
	top = *stack;
	second = top->lower;
	bottom = stack_bottom(top);
	top->upper = bottom;
	top->lower = NULL;
	second->upper = NULL;
	bottom->lower = top;
	*stack = second;
	return (true);
}

void	ra(t_stack **stack_a)
{
	if (node_rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	if (node_rotate(stack_b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	bool	rotate_a;
	bool	rotate_b;

	rotate_a = node_rotate(stack_a);
	rotate_b = node_rotate(stack_b);
	if (rotate_a || rotate_b)
		write(1, "rr\n", 3);
}
