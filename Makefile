NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c ft_error_cases.c ft_split.c ft_stack.c ft_units.c ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c ft_sort_small.c ft_radix_sort.c print.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
