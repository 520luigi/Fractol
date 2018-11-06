# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szheng <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 20:12:07 by szheng            #+#    #+#              #
#    Updated: 2018/11/05 20:52:57 by szheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fractol

NOC		=	\033[0m
GREEN	=	\033[1;32m
YELLOW = \033[1;33m
BLUE	=	\033[1;34m
RED		=	\033[1;31m

SRCS = srcs/main.c srcs/fractol.c srcs/draw.c srcs/colorset.c srcs/setup.c \
	   srcs/keys.c srcs/mouse.c

INC = -I includes/fractol.h -I libft/

LIB = -L minilibx_macos/ -l mlx -L libft/ -lft

FRM = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@mkdir -p obj/
	@make -C minilibx_macos
	@make -C libft
	@gcc -Wall -Werror -Wextra -c $(SRCS) $(INC)
	@mv *.o obj/
	@gcc obj/*.o $(LIB) -o $(NAME) $(FRM)
	@echo "$(GREEN)Fractol is ready to go!$(NOC)"
	@echo "$(YELLOW)    _       _       _"
	@echo " __(.)<  __(.)>  __(.)="
	@echo " \___)   \___)   \___)$(NOC)"

clean:
	@make -C minilibx_macos/ clean
	@make -C libft/ clean
	@rm -rf obj/
	@echo "$(BLUE)Removed Object files$(NOC)"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(RED)Removed Fractol executable$(NOC)"

re: fclean all
