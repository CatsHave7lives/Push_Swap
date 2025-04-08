/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:53:33 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/08 16:04:17 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_bottom(t_stack *node)
{
	while (node && node->lower)
		node = node->lower;
	return (node);
}

bool	stack_is_duplicate(t_stack *node, int value)
{
	while (node)
	{
		if (node->value == value)
			return (true);
		node = node->lower;
	}
	return (false);
}

int	stack_size(t_stack *stack)
{
	t_stack	*node;
	int		size;

	node = stack;
	size = 0;
	while (node)
	{
		size++;
		node = node->lower;
	}
	return (size);
}

t_stack	*stack_value_lowest(t_stack *stack)
{
	t_stack	*n_i;
	t_stack	*n_value_lowest;
	int		value_lowest;

	n_i = stack;
	n_value_lowest = NULL;
	value_lowest = INT_MAX;
	while (n_i)
	{
		if (n_i->value <= value_lowest)
		{
			value_lowest = n_i->value;
			n_value_lowest = n_i;
		}
		n_i = n_i->lower;
	}
	return (n_value_lowest);
}
