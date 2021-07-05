# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 17:33:19 by kaye              #+#    #+#              #
#    Updated: 2021/07/05 18:39:47 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC		= clang
CFLAGS 	= -Wall -Wextra -Werror -fsanitize=address
IFLAGS 	= -I./incs -I./libft/inc -I./mlx/
LFLAGS	= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

# DIRECTORIES

BUILD 			:= .build
SRC_DIR 		:= srcs
SUB_DIR 		:= engine \
		   		   events \
		   	 	   parser \
				   utils
OBJ_DIR 		:= $(BUILD)/obj
LIBFT_DIR		:= ./libft
DIRS			:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILES

NAME			:= so_long
SRC				:= main.c
SUB_SRC			:= image.c \
				   so_long.c
SRC				+= $(addprefix engine/, $(SUB_SRC))
SUB_SRC			:= event_key.c \
				   event.c
SRC				+= $(addprefix events/, $(SUB_SRC))
SUB_SRC			:= parser.c \
				   parser_check.c \
				   tex_load.c
SRC				+= $(addprefix parser/, $(SUB_SRC))
SUB_SRC			:= utils.c
SRC				+= $(addprefix utils/, $(SUB_SRC))
OBJ				:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COLORS

NONE			= \033[0m
CL_LINE			= \033[2K
S_CURSUS		= \033[s
J_CURSUS		= \033[u
B_BLACK			= \033[1;30m
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_YELLOW		= \033[1;33m
B_BLUE			= \033[1;34m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

# MAKEFILE

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(CL_LINE)$(J_CURSUS)"
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) -o $@ $(LFLAGS)
	@echo "Compilation of $(B_RED)$@$(NONE) done"

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -Rf $(BUILD)
	@echo "$(B_RED)$(BUILD)$(NONE) -> $(B_GREEN)Delete$(NONE)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -Rf $(NAME)
	@echo "$(B_RED)$(NAME)$(NONE)  -> $(B_GREEN)Delete$(NONE)"

re: fclean all

.PHONY: all clean fclean re

$(BUILD):
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs object : $(B_CYAN)$< $(NONE)...\r$(S_CURSUS)"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@