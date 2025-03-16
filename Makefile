# Files:
HEADER  =   push_swap.h
FILES   =   node_swap.c         node_push.c         node_rotate.c       node_reverse.c	\
            get_from_stack.c    utils_basic.c       utils_advanced.c    main.c

#FILES_B =   

NAME    =   push_swap

OBJS    =   $(FILES:.c=.o)
#OBJS_B  =   $(FILES_B:.c=.o)

CC      =   cc
FLAGS   =   -Wall -Wextra -Werror

AR      =   ar crs
RM      =   rm -f

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

#bonus: $(OBJS_B)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean