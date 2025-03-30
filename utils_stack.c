/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:53:33 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/30 18:22:10 by aessaber         ###   ########.fr       */
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

void	stack_free(t_stack **stack)
{
	t_stack	*node;
	t_stack	*node_lower;

	if (!stack || !*stack)
		return ;
	node = *stack;
	while (node)
	{
		node_lower = node->lower;
		free(node);
		node = node_lower;
	}
}

t_stack	*stack_metadata(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index = 0;
	node->value = value;
	node->m_cost = 0;
	node->is_best = false;
	node->upper = NULL;
	node->lower = NULL;
	return (node);
}
