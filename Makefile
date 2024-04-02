# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 16:49:02 by rsaueia-          #+#    #+#              #
#    Updated: 2024/04/02 19:24:31 by rsaueia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

NAME = fractol
CC = cc
HEADER = fractol.h
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
CFLAGS	= -Wall -Wextra -Werror

# **************************************************************************** #
# SOURCES

SRC = fractol.c events.c fractol_init.c math_aux.c render.c string_aux.c 
OBJ = $(SRC:.c=.o)

# **************************************************************************** #
# RULES

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re
