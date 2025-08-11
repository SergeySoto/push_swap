NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = push_swap.c

INCLUDE = ./libft/libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

# regla para crear la biblioteca
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# pasar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

ejecutarall:
	$(CC) $(CFLAGS) *.c -o push_swap_test
	./push_swap_test

# regla para eliminar todos los archivos objetos creados
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

# Eliminar todos los archivos .o y .a
fclean: clean
	rm -f $(NAME) push_swap_test
	$(MAKE) fclean -C $(LIBFT_DIR)

# recompila
re: fclean all

# indica que las siguientes reglas no son archivos reales
.PHONY: all bonus clean fclean re ejecutarall