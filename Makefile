# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#              #
#    Updated: 2022/03/08 17:30:06 by pguignie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d

CC      = clang

FLAGS   = -Wall -Wextra -Werror

CFLAGS = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

INCLUDE = include

SRC_PATH    = src

OBJ_PATH    = obj

SOURCES =   mlx.c \
			hit.c \
			lst.c \
			main.c \
			free.c \
			draw.c \
			utils.c \
			render.c \
			vector.c \
			parsing.c \
			minimap.c \
			sprites.c \
			key_hook.c \
			init_mlx.c \
			ft_split.c \
			vector_op.c \
			raycasting.c \
			mouse_hook.c \
			parsing_init.c \
			get_next_line.c \
			parsing_utils.c \
			ft_split_parsing.c \
			parsing_fill_map.c \
			parsing_utils_bis.c \
			raycasting_utils.c \
			parsing_check_map.c \
			get_next_line_utils.c \
			parsing_check_colors.c \
			parsing_check_textures.c \

PATH_MLX = mlx_linux

SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))

OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

	NOC     = \033[0m
	RED     = \033[1;31m
	GREEN   = \033[1;32m
	YELLOW  = \033[1;33m
	BLUE    = \033[1;34m
	WHITE   = \033[1;37m

all: libs
	@make $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ $(CFLAGS)
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(INCLUDE) -c -o $@ $<
	@echo "$(BLUE)gcc $(WHITE)$(notdir $@)$(NOC)"

libs:
	@make -sC mlx_linux

clean:
	@echo "$(RED)clean$(NOC)"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
