/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:08 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/08 23:10:25 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				value;
	int				rank;
	int				move_cost;
	bool			above_mid;
	bool			is_best;
	struct s_stack	*upper;
	struct s_stack	*lower;
	struct s_stack	*a_target;
}	t_stack;

// build_stack.c
char	**build_stack(t_stack **stack_a, char **av, bool ac2);

// free_error.c
void	free_stack(t_stack **stack);
void	free_arg(char **av, bool check);
void	error_exit(void);
void	free_error(t_stack **stack, char **av, bool check);

// ft_atol.c
bool	ft_issign(char c);
bool	ft_isdigit(char c);
long	ft_atol(const char *str);

// ft_split.c
char	**ft_split(char const *s, char c);

// utils_libft.c
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// utils_stack.c
t_stack	*stack_bottom(t_stack *node);
bool	stack_is_duplicate(t_stack *node, int value);
int		stack_size(t_stack *stack_a);
t_stack	*stack_value_lowest(t_stack *stack);

// utils_build.c
char	**append_to_array(char **av_current, int spot);
void	build_node(t_stack **stack_a, int value);

// utils_update.c
void	update_target(t_stack **stack_a, t_stack **stack_b);
void	update_move_cost(t_stack **stack_a, t_stack **stack_b);

// update_stack.c
void	update_stack(t_stack **stack_a, t_stack **stack_b);

// sort_stack.c
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

// node_swap.c
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// node_push.c
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// node_rotate.c
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// node_reverse.c
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif