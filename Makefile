#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/06 16:20:15 by tchezier          #+#    #+#              #
#    Updated: 2015/06/09 15:57:21 by tchezier         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = ./main.c	\
	./get_next_line/get_next_line.c	\
	./gettable.c	\
	./getlinenb.c	\
	./ft_win.c	\
	./freetab.c	\
	./expose_hook.c	\
	./key_hook.c	\
	./tablen.c	\
	./red_line.c	\
	./blue_line.c	\
	./read_linenb.c	\
	./read_table.c	\
	./showz.c	\
	./trace_map.c	\
	./swap.c	\
	./way.c

OBJ = ./main.o	\
	./get_next_line.o	\
	./gettable.o	\
	./getlinenb.o	\
	./ft_win.o	\
	./freetab.o	\
	./expose_hook.o	\
	./key_hook.o	\
	./tablen.o	\
	./red_line.o	\
	./blue_line.o	\
	./read_linenb.o	\
	./read_table.o	\
	./showz.o	\
	./trace_map.o	\
	./swap.o	\
	./way.o

FDFH = ./

GNLH = ./get_next_line/

LIBFTH = ./libft/includes/

MLXH = ./minilibx_macos/

FWK = -framework OpenGL -framework AppKit

WFLAGS = -Wall -Werror -Wextra

LIBS = ./libft/libft.a	\
	./minilibx_macos/libmlx.a

all: $(NAME)

$(NAME):
			@make -C ./minilibx_macos/ re
			@make -C ./libft/ re
			gcc $(WFLAGS) -I $(GNLH) -I $(FDFH) -I $(LIBFTH) -I $(MLXH) -c $(SRC)
			gcc $(FWK) $(WFLAGS) -L ./libft/ -L ./minilibx_macos/ -I $(GNLH) -I $(FDFH) -I $(LIBFTH) -I $(MLXH) -lft -lm -lmlx $(OBJ) -o $(NAME)

clean: 
			rm -rf $(OBJ)

fclean:
			make clean
			rm -rf $(NAME) $(LIBS)

re:
			make fclean
			make all