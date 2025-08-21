NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

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
       ops_reverse_rot.c

OBJS		= $(SRCS:.c=.o)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_A) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
