# Files:
NAME    =   push_swap
HEADER  =   push_swap.h
FILES   =   build_stack.c       free_error.c        ft_atol.c           ft_split.c      \
            main.c              node_push.c         node_reverse.c      node_rotate.c   \
            node_swap.c         sort_stack.c        update_stack.c      utils_build.c   \
            utils_libft.c       utils_sort.c        utils_stack.c       utils_update.c

OBJS    =   $(FILES:.c=.o)
#FILES_B =   
#OBJS_B  =   $(FILES_B:.c=.o)

# Shell commands:
CC      =   cc
FLAGS   =   -Wall -Wextra -Werror
RM      =   rm -f

# Rules:
all: $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

#bonus: $(OBJS_B)
 
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean