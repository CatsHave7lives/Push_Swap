/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:37 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/15 15:29:23 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	node_push(t_stack **src_stack, t_stack **dst_stack)
{
	t_stack	*src_top;
	t_stack	*dst_top;
	t_stack	*src_second;

	if (!src_stack || !*src_stack || !dst_stack)
		return (false);
	src_top = *src_stack;
	dst_top = *dst_stack;
	src_second = src_top->lower;
	src_top->lower = dst_top;
	if (src_second)
		src_second->upper = NULL;
	if (dst_top)
		dst_top->upper = src_top;
	*dst_stack = src_top;
	*src_stack = src_second;
	return (true);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (node_push(stack_b, stack_a))
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (node_push(stack_a, stack_b))
		write(1, "pb\n", 3);
}
