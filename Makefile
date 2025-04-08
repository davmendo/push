# Makefile for push_swap and checker

NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_PUSH_SWAP = push_swap_main.c operations1.c operations2.c operations3.c \
				 sorting.c sorting_small.c utils.c
SRCS_CHECKER = checker_main.c operations1.c operations2.c operations3.c utils.c

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_PUSH_SWAP)

checker: $(OBJS_CHECKER)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS_CHECKER)

clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
