/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:46:27 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/05 21:13:39 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_arraylen(char **array)
{
	size_t	row;

	if (!array)
		return (0);
	row = 0;
	while (array[row])
		row++;
	return (row);
}

static void	fill_new_av(char **av_rep, char **av_cur, char **array, int spot)
{
	int		row;
	int		i;

	row = 0;
	while (row < spot)
	{
		av_rep[row] = ft_strdup(av_cur[row]);
		row++;
	}
	i = 0;
	while (array[i])
	{
		av_rep[row] = ft_strdup(array[i]);
		row++;
		i++;
	}
	while (av_cur[++spot])
		av_rep[row++] = ft_strdup(av_cur[spot]);
	av_rep[row] = NULL;
}

char	**append_to_array(char **av_current, int spot)
{
	char	**array;
	char	**av_replace;
	size_t	len;

	array = ft_split(av_current[spot], ' ');
	if (!array || !array[0])
		return (free_arg(array, true), NULL);
	len = ft_arraylen(av_current) + ft_arraylen(array) -1;
	av_replace = (char **)malloc(sizeof(char *) * (len +1));
	if (!av_replace)
		return (free_arg(array, true), NULL);
	fill_new_av(av_replace, av_current, array, spot);
	return (free_arg(array, true), av_replace);
}

static t_stack	*stack_metadata(int value)
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

void	build_node(t_stack **stack_a, int value)
{
	t_stack	*node_current;
	t_stack	*node_add;

	if (!stack_a)
		return ;
	node_add = stack_metadata(value);
	if (!node_add)
		return ;
	if (!*stack_a)
		*stack_a = node_add;
	else
	{
		node_current = *stack_a;
		while (node_current->lower)
			node_current = node_current->lower;
		node_current->lower = node_add;
		node_add->upper = node_current;
	}
}
