/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:47 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 22:53:57 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stack(t_stack **stack)
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

void	free_arg(char **av, bool check)
{
	int	i;

	if (!check || !av)
		return ;
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_error(t_stack **stack, char **av, bool check)
{
	free_stack(stack);
	free_arg(av, check);
	error_exit();
}
