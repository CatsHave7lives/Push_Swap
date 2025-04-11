/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:08 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 22:53:13 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

// build_stack_bonus.c
char	**build_stack(t_stack **stack_a, char **av, bool ac2);

// free_error_bonus.c
void	free_stack(t_stack **stack);
void	free_arg(char **av, bool check);
void	error_exit(void);
void	free_error(t_stack **stack, char **av, bool check);

// ft_atol_bonus.c
bool	ft_issign(char c);
bool	ft_isdigit(char c);
long	ft_atol(const char *str);

// ft_split_bonus.c
char	**ft_split(char const *s, char c);

// utils_libft_bonus.c
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// utils_stack_bonus.c
t_stack	*stack_bottom(t_stack *node);
bool	stack_is_duplicate(t_stack *node, int value);
int		stack_size(t_stack *stack_a);
t_stack	*stack_value_lowest(t_stack *stack);

// utils_build_bonus.c
char	**append_to_array(char **av_current, int spot);
void	build_node(t_stack **stack_a, int value);

// utils_update_bonus.c
void	update_move_cost(t_stack **stack_a, t_stack **stack_b);
void	update_target(t_stack **stack_a, t_stack **stack_b);

// update_stack_bonus.c
void	update_stack(t_stack **stack_a, t_stack **stack_b);

// utiles_sort_bonus.c
void	sort_rank(t_stack **stack_a, t_stack **stack_b);
void	sort_to_a(t_stack **stack_a, t_stack **stack_b);

// sort_stack_bonus.c
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// node_swap_bonus.c
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// node_push_bonus.c
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// node_rotate_bonus.c
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// node_reverse_bonus.c
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		validate_move(char *move, t_stack **stack_a, t_stack **stack_b);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(char *s1);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

#endif