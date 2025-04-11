/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:12:59 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 22:15:43 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (i < n && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

int	validate_move(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(move, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(move, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(move, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(move, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(move, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrb(stack_b);
	else
		return (1);
	return (0);
}
