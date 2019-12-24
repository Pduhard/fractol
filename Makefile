# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 00:29:26 by pduhard-     #+#   ##    ##    #+#        #
#    Updated: 2019/12/21 08:18:53 by pduhard-    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#__________CONFIG__________#

NAME		=	fractol

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -O3
FRAMEWORK	=	-framework OpenGL -framework AppKit
LIB_FLAGS	=	-L$(LIB_PATH) $(LIB_FLAG)
MLX_FLAGS	=	-L$(MLX_PATH) $(MLX_FLAG)
INCLUDES	=	fractol.h	\

SRC_PATH	=	./srcs/
BIN_PATH	=	./bins/
INC_PATH	=	./includes/
LIB_PATH	=	./libft/
MLX_PATH	=	./minilibx_macos/

SRC			=	main.c			\
				init.c			\
				complex.c		\
				pixels.c		\
				loop.c			\
				mouse_hook.c	\
				key_hook.c		\
				fractal_utils.c	\
				mandelbrot.c	\
				julia.c			\
				sepiensky.c		\
				colors.c		\
				free.c			\

BIN			=	$(SRC:.c=.o)

LIB_FLAG			=	-lft
LIB					=	libft.a
MLX_FLAG			=	-lmlx
MLX					=	libmlx.a

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
BINS		=	$(addprefix $(BIN_PATH), $(BIN))
LIBS		=	$(addprefix $(LIB_PATH), $(LIB))
INCS		=	$(addprefix $(INC_PATH), $(INCLUDES))
MLXS		=	$(addprefix $(MLX_PATH), $(MLX))

.PHONY: all clean fclean re lib

#__________COLORS__________#

R			=	\033[0;31m
G			=	\033[32;7m
B			=	\033[0;34m
N			=	\33[0m

#__________RULES__________#

all: $(NAME)

	@make -C $(LIB_PATH)

$(NAME): $(LIBS) $(MLXS) $(BINS)

	@$(CC) -I $(INC_PATH) $(FLAGS) -lpthread $(LIB_FLAGS) $(MLX_FLAGS) $(FRAMEWORK) $^ -o $@
	@echo "\n\n$(B)[EXECUTABLE \"$(NAME)\" READY]\n"

$(LIBS):

	@make -C $(LIB_PATH)

$(MLXS):

	@make -C $(MLX_PATH)

$(BIN_PATH)%.o: $(SRC_PATH)%.c $(INCS)

	@mkdir -p $(BIN_PATH) || true
	@$(CC) $(FLAGS) -I $(INC_PATH) -o $@ -c $< && echo "${G} \c"

clean:

	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@echo "${R}[CLEANING $(NAME) BINARIES]"
	@rm -f $(BINS)

fclean: clean

	@echo "\n${R}[REMOVING "libft.a"]"
	@rm -rf $(LIB_PATH)/libft.a
	@echo "\n${R}[REMOVING "libmlx.a"]"
	@rm -rf $(MLX_PATH)/libmlx.a
	@echo "\n${R}[REMOVING \"$(NAME)\"]\n"
	@rm -f $(NAME)

re: fclean all

