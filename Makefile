#
#
#
# 			ADAPTAR
#
#
#


CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

# Colores
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Lista de archivos fuente
SRCS =


# Generar lista de archivos objeto (.o) a partir de los .c
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(NAME)

# Regla para crear la biblioteca
$(NAME): $(OBJS)
	@echo "$(GREEN)Construyendo $(NAME)$(RESET)"
	@echo "$(GREEN)Creando la biblioteca $(NAME)$(RESET)"
	ar rcs $@ $^

# Regla para compilar los archivos fuente en objetos
%.o: %.c
	@echo "$(CYAN)Compilando $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas para limpiar los archivos objeto y la biblioteca
clean:
	@echo "$(RED)Limpiando archivos objeto$(RESET)"
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "$(RED)Limpiando la biblioteca $(NAME)$(RESET)"
	rm -rf $(NAME)

# Regla para recompilar todo
re: fclean all
	@echo "$(YELLOW)Recompilando todo$(RESET)"
