NAME		= so_long

# Libraries
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= printf
PRINTF		= $(PRINTF_DIR)/printf.a

# Sources & Headers
SRCS		= $(wildcard src/*.c)
HEADERS		= includes/so_long.h

# Compiler settings
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g -O0
INC			= -I ./includes -I ./src

AR			= ar rcs
RM			= rm -rf

# ========================= #
#      OS DETECTION         #
# ========================= #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_DIR		= mlx/mlx_linux
	MLX_LIB		= $(MLX_DIR)/libmlx.a
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
	MLX_INC		= -I$(MLX_DIR)
else ifeq ($(UNAME_S), Darwin)
	MLX_DIR		= mlx/mlx_mac
	MLX_LIB		= $(MLX_DIR)/libmlx.a
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	MLX_INC		= -I$(MLX_DIR)
	CFLAGS		+= -DGL_SILENCE_DEPRECATION
endif

# ========================= #
#         RULES             #
# ========================= #

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS) $(LIBFT) $(PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INC) $(MLX_INC) $(SRCS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@echo "\n🧱 Building libft..."
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "\n🖨️  Building printf..."
	@make -C $(PRINTF_DIR)

$(MLX_LIB):
	@echo "\n🎨 Building MiniLibX..."
	@make -C $(dir $(MLX_LIB))

clean:
	@echo "\n🧹 Cleaning object files..."
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(dir $(MLX_LIB))
	@$(RM) src/*.o

fclean: clean
	@echo "\n🔥 Full clean..."
	@make fclean -C $(PRINTF_DIR)
	@$(RM) $(NAME)

re: fclean all

run: all
	@./$(NAME) maps/map.ber

# ========================= #
#        PHONY              #
# ========================= #
.PHONY: all clean fclean re run