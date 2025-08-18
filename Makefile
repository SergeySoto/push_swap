NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

# Directories
SRC_DIR = .
OBJ_DIR = obj
LIBFT_DIR = ./libft/
CHECK_UTILS_DIR = check_utils
INCLUDE = ./libft/libft.h

# Library
LIBFT = $(LIBFT_DIR)libft.a

# Source files
SRC = push_swap.c push_pars.c push_utils.c func_error.c nodes.c \
      $(CHECK_UTILS_DIR)/prints.c

# Object files (with obj/ prefix)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# Default rule
all: $(NAME)

# Build main program
$(NAME): $(OBJ) $(LIBFT)
	@echo "🔧 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME) && \
		echo "✅ Build successful!" || echo "❌ Build failed!"

# Compile .c to .o into obj/
$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "🟢 Compiled $<" || echo "🔴 Failed to compile $<"

# Compile libft with messages
$(LIBFT):
	@echo "📦 Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@if [ $$? -eq 0 ]; then \
		echo "✅ libft compiled successfully!"; \
	else \
		echo "❌ Failed to compile libft!"; \
		exit 1; \
	fi

# Rule to run a test build
ejecutarall: $(SRC) $(LIBFT)
	@echo "🚀 Compiling test version..."
	@$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -lft -o push_swap_test && \
		./push_swap_test

# Clean object files
clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	@echo "🧹 Removing binaries..."
	@rm -f $(NAME) push_swap_test
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild all
re: fclean all

.PHONY: all clean fclean re ejecutarall


# NAME = push_swap

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -I./libft

# LIBFT_DIR = ./libft/
# LIBFT = $(LIBFT_DIR)libft.a

# SRC = push_swap.c push_pars.c push_utils.c func_error.c nodes.c\
# 		check_utils/prints.c

# INCLUDE = ./libft/libft.h

# OBJ = $(SRC:.c=.o)

# all: $(NAME)

# # rule for the library
# $(NAME): $(OBJ) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# # from .c to .o
# %.o: %.c $(INCLUDE)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# ejecutarall:
# 	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -lft -o push_swap_test
# 	./push_swap_test

# # rule to delete all the .o created
# clean:
# 	rm -f $(OBJ)
# 	rm -f check_utils/*.o
# 	$(MAKE) -C $(LIBFT_DIR) clean

# # delete all files .o and .a
# fclean: clean
# 	rm -f $(NAME) push_swap_test
# 	$(MAKE) -C $(LIBFT_DIR) fclean

# re: fclean all

# .PHONY: all bonus clean fclean re ejecutarall