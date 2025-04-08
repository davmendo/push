# Makefile for push_swap and checker with libft

NAME = push_swap
CHECKER = checker
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fontes para push_swap
SRCS_PUSH_SWAP = push_swap_main.c operations1.c operations2.c operations3.c \
                 sorting.c sorting_small.c utils.c
# Fontes para checker
SRCS_CHECKER = checker_main.c operations1.c operations2.c operations3.c utils.c

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all: $(NAME)

# Regra para compilar a libft antes de linkar os binários
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS_PUSH_SWAP) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_PUSH_SWAP) $(LIBFT)

checker: $(OBJS_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS_CHECKER) $(LIBFT)

clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

