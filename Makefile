FILES       =   node_swap.c         node_push.c         node_rotate.c       node_reverse.c	\
                get_from_stack.c    utils_basic.c       utils_advanced.c    \

FILES_BONUS	=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c		ft_lstlast_bonus.c	\
				ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c		ft_lstclear_bonus.c		ft_lstiter_bonus.c	\
				ft_lstmap_bonus.c

NAME		= libft.a

OBJS		= $(FILES:.c=.o)
OBJS_BONUS	= $(FILES_BONUS:.c=.o)

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

AR			= ar crs
RM			= rm -f

all: $(NAME)
 
$(NAME): $(OBJS)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@
	$(AR) $(NAME) $@

bonus: $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean