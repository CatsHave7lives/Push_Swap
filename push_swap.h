/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:08 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/16 17:31:03 by aessaber         ###   ########.fr       */
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
	struct s_stack	*upper;
	struct s_stack	*lower;
}	t_stack;

// utils_basic.c
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_is_overflowed(int sign);
// utils_advanced.c
int		ft_atoi(const char *str);
// get_from_stack.c
t_stack	*stack_bottom(t_stack *stack);
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
#endif //"" "    " 
//1 5 6 7 2 " 11 58 67" 22 78 63
//"++8 --7 +1- -9+ 1- 5"
//"+8"