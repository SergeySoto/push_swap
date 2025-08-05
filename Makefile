NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c

INCLUDE = ./libft/libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

# regla para crear la biblioteca
$(NAME): $(OBJ)  
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# pasar archivos .c a .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

ejecutarall:
	$(CC) $(CFLAGS) *.c -o push_swap_test
	./push_swap_test

# regla para eliminar todos los archivos objetos creados
clean:
	rm -f $(OBJ)

# Eliminar todos los archivos .o y .a
fclean: clean
	rm -f $(NAME) push_swap_test

# recompila
re: fclean all

# indica que las siguientes reglas no son archivos reales
.PHONY: all bonus clean fclean re ejecutarall