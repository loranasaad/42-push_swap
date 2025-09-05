NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I.

SRCS = push_swap.c \
       parse_input.c \
       sort_small.c \
       sort_big.c \
       sort_utilities.c \
       sort_utilities_2.c \
       sort_utilities_3.c \
       stack_utilities.c \
       ops_swap.c \
       ops_push.c \
       ops_rotate.c \
       ops_reverse_rot.c \
       atoi_safe.c \
	   ft_split.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re