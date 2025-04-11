# Files:
NAME    =   push_swap
CHECKER =   checker
HEADER  =   push_swap.h
HEADER_B=   checker_bonus.h
FILES   =   build_stack.c       free_error.c        ft_atol.c           ft_split.c      \
            push_swap_main.c    node_push.c         node_reverse.c      node_rotate.c   \
            node_swap.c         sort_stack.c        update_stack.c      utils_build.c   \
            utils_libft.c       utils_sort.c        utils_stack.c       utils_update.c
FILES_B =   build_stack_bonus.c     free_error_bonus.c  ft_atol_bonus.c         ft_split_bonus.c        \
            checker_main_bonus.c    node_push_bonus.c   node_reverse_bonus.c    node_rotate_bonus.c     \
            node_swap_bonus.c       sort_stack_bonus.c  update_stack_bonus.c    utils_build_bonus.c     \
            utils_libft_bonus.c     utils_sort_bonus.c  utils_stack_bonus.c     utils_update_bonus.c    \
            validation_bonus.c      get_next_line_bonus.c   get_next_line_utils_bonus.c
OBJS    =   $(FILES:.c=.o)
OBJS_B  =   $(FILES_B:.c=.o)

# Shell commands:
CC      =   cc
FLAGS   =   -Wall -Wextra -Werror
RM      =   rm -f

# Rules:
all: $(NAME) $(CHECKER)
 
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(CHECKER): $(OBJS_B)
	$(CC) $(FLAGS) $(OBJS_B) -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER_B)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: clean