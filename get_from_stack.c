/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:53:33 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/06 11:11:09 by aessaber         ###   ########.fr       */
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
