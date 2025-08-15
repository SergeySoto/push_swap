NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = push_swap.c push_pars.c push_utils.c func_error.c \
		check_utils/printsss.c

INCLUDE = ./libft/libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

# rule for the library
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# from .c to .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

ejecutarall:
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -lft -o push_swap_test
	./push_swap_test

# rule to delete all the .o created
clean:
	rm -f $(OBJ)
	rm -f check_utils/*.o
	$(MAKE) -C $(LIBFT_DIR) clean

# delete all files .o and .a
fclean: clean
	rm -f $(NAME) push_swap_test
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re ejecutarall