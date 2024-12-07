NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directorios
SRC_DIR = src
INCLUDE_DIR = includes
BONUS_SRC_DIR = src_bonus
BONUS_INCLUDE_DIR = includes_bonus
GNL_DIR = gnl

# Colores
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Archivos fuente y objetos para push_swap
SRC = $(addprefix $(SRC_DIR)/, main.c rule_push.c rule_rev_rotate.c rule_rotate.c rule_swap.c wrong_input.c sort_big_stack.c \
sort_small_stack.c get_cheaper_index.c general_utils.c wrong_input_utils.c sort_big_stack_utils.c get_cheaper_index_utils.c)
OBJ = $(SRC:.c=.o)

# Archivos fuente y objetos para checker
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR)/, main.c rule_push.c rule_rev_rotate.c rule_rotate.c rule_swap.c \
wrong_input.c wrong_input_utils.c general_utils.c free.c errors.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)

BONUS_OBJ = $(BONUS_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)


# Ruta a la biblioteca libft.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Regla principal
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN)Construyendo $(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Regla para compilar la biblioteca libft
$(LIBFT):
	@echo "$(CYAN)Compilando la biblioteca libft$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS_OBJ) $(GNL_OBJ) $(LIBFT)
	@echo "$(GREEN)Construyendo $(NAME_BONUS)$(RESET)"
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(GNL_OBJ) $(LIBFT) -o $(NAME_BONUS)


# Reglas para limpiar los archivos objeto y la biblioteca
clean:
	@echo "$(RED)Limpiando archivos objeto$(RESET)"
	rm -rf $(OBJ) $(BONUS_OBJ) $(GNL_OBJ)
	@echo "$(RED)Limpiando libft$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Limpiando $(NAME) y $(NAME_BONUS) $(RESET)"
	rm -rf $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Regla para recompilar todo
re: fclean all
	@echo "$(YELLOW)Recompilando todo$(RESET)"
