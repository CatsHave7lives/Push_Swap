/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:08 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/27 12:21:48 by aessaber         ###   ########.fr       */
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

// utils_libft.c
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
// utils_arg.c
void	error_exit(char *str);
void	arg_free(char **av, bool check);
char	**arg_check(int ac, char **av);
// utils_atoi.c
int		ft_atoi(const char *str);
// utils_split.c
char	**ft_split(char const *s, char c);
// utils_stack.c
t_stack	*stack_bottom(t_stack *stack);
bool	stack_is_duplicate(t_stack *node, int value);
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