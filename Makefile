# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#              #
#    Updated: 2022/03/14 11:01:39 by lcavallu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d

BONUS_NAME = cub3d_bonus

CC      = clang

FLAGS   = -Wall -Wextra -Werror

CFLAGS = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

INCLUDE = include

SRC_PATH    = src

BNS_PATH    = bonus

OBJ_PATH    = obj

OBJBNS_PATH = objbns

SOURCES =   key.c \
			mlx.c \
			hit.c \
			main.c \
			free.c \
			draw.c \
			utils.c \
			render.c \
			vector.c \
			parsing.c \
			key_hook.c \
			init_mlx.c \
			ft_split.c \
			vector_op.c \
			raycasting.c \
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

BONUS =	utils.c \
		vector.c \
		ft_split.c \
		vector_op.c \
		raycasting.c \
		get_next_line.c \
		parsing_utils.c \
		ft_split_parsing.c \
		parsing_utils_bis_bonus.c \
		raycasting_utils.c \
		get_next_line_utils.c \
		hit_bonus.c \
		move.c \
		door.c \
		time.c \
		mlx_handle.c \
		draw_bonus.c \
		free_bonus.c \
		init_mlx_bonus.c \
		key_hook_bonus.c \
		main_bonus.c \
		mlx_bonus.c \
		parsing_bonus.c \
		parsing_check_colors_bonus.c \
		parsing_check_map_bonus.c \
		parsing_check_textures_bonus.c \
		parsing_fill_map_bonus.c \
		parsing_init_bonus.c \
		render_bonus.c \
		lst.c \
		minimap.c \
		mouse_hook.c \
		sprites.c \
		draw_sprites.c \
		get_color.c

PATH_MLX = mlx_linux

SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))

BNS = $(addprefix $(BNS_PATH)/,$(BONUS))

OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

OBJBNS = $(addprefix $(OBJBNS_PATH)/,$(BONUS:.c=.o))

	NOC     = \033[0m
	RED     = \033[1;31m
	GREEN   = \033[1;32m
	YELLOW  = \033[1;33m
	BLUE    = \033[1;34m
	WHITE   = \033[1;37m

all: libs
	@make $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o cub3D $^ $(CFLAGS)
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) -I$(INCLUDE) -c -o $@ $<
	@echo "$(BLUE)gcc $(WHITE)$(notdir $@)$(NOC)"

$(OBJBNS_PATH)/%.o: $(BNS_PATH)/%.c $(INCLUDE)/$(BONUS_NAME).h
	@mkdir -p objbns
	@$(CC) $(FLAGS) -I$(INCLUDE) -c -o $@ $<
	@echo "$(BLUE)gcc $(WHITE)$(notdir $@)$(NOC)"

libs:
	@make -sC mlx_linux

bonus: libs
	@make $(BONUS_NAME)

$(BONUS_NAME): $(OBJBNS)
	@$(CC) $(FLAGS) -o cub3D_bonus $^ $(CFLAGS)
	@echo "$(GREEN)$@$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJBNS_PATH)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@rm -f cub3D
	@rm -f cub3D_bonus

re: fclean all

.PHONY: all clean fclean re
