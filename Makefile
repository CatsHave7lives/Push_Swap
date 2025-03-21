# Files:
NAME    =   push_swap
HEADER  =   push_swap.h
FILES   =   node_swap.c         node_push.c         node_rotate.c       node_reverse.c	\
            get_from_stack.c    utils_basic.c       utils_advanced.c    main.c
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