CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes
NAME = push_swap

# Colores
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Lista de archivos fuente
SRCS = srcs/main.c \
instructions/rule_push.c instructions/rule_rev_rotate.c instructions/rule_rotate.c instructions/rule_swap.c \
check_errors/wrong_input.c sort/sort_big_stack.c sort/sort_small_stack.c sort/get_cheaper_index.c \
srcs/general_utils.c check_errors/wrong_input_utils.c sort/sort_big_stack_utils.c sort/get_cheaper_index_utils.c \

# Generar lista de archivos objeto (.o) a partir de los .c
OBJS = $(SRCS:.c=.o)

# Ruta a la biblioteca libft.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Regla principal
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(GREEN)Construyendo $(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Regla para compilar los archivos fuente en objetos
%.o: %.c
	@echo "$(CYAN)Compilando $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar la biblioteca libft
$(LIBFT):
	@echo "$(CYAN)Compilando la biblioteca libft$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

# Reglas para limpiar los archivos objeto y la biblioteca
clean:
	@echo "$(RED)Limpiando archivos objeto$(RESET)"
	rm -rf $(OBJS)
	@echo "$(RED)Limpiando libft$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Limpiando la biblioteca $(NAME)$(RESET)"
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Regla para recompilar todo
re: fclean all
	@echo "$(YELLOW)Recompilando todo$(RESET)"
