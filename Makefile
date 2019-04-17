# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 16:54:47 by amontano          #+#    #+#              #
#    Updated: 2019/04/14 20:42:11 by amontano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_canvas
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
FRAMEWORKS = -framework OpenGL -framework Appkit
SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./includes

LIBFT = ./libft
MLX = ./minilibx_macos


SOURCE = main.c				\
		 mouse.c			\
		 img.c				\
		 render.c			\
		 keyboard.c			\
		 draw.c				\
		 draw_line.c		\
		 draw_ellipse.c		\
		 draw_bucket.c		\
		 util.c				\
		 frame_buffer.c		\
		 color_pick_gui.c	\
		 init_store.c		\


SRC = $(addprefix $(SRCDIR)/, $(SOURCE))
OBJ = $(addprefix $(OBJDIR)/, $(SOURCE:.c=.o))
INC = $(addprefix -I, $(INCDIR))

.PHONY: all clean fclean re
.SILENT:

all: build $(NAME)

$(NAME) : $(OBJ)
		make -C $(LIBFT)
		make -C $(MLX)
		$(CC) $(CFLAGS) -L $(LIBFT) -lft -L $(MLX) -lmlx $(FRAMEWORKS) -o $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) -I $(LIBFT)/includes -I $(MLX) -o $@ -c $<

build:
	mkdir -p $(OBJDIR)

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

install: all clean

re: fclean all

