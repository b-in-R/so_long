# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabiner <rabiner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 18:58:05 by rabiner           #+#    #+#              #
#    Updated: 2025/04/29 11:28:23 by rabiner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
LIBFT_DIR = libft
SRC_DIR = src
GNL_DIR = gnl

SRCS = game.c main.c map.c moving.c \
		path.c player.c render_utils.c \
		render.c utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a
GNL_A = $(GNL_DIR)/gnl.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -lz
INCLUDES = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -I$(SRC_DIR) -I/usr/include

SANITIZE_FLAGS = -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(GNL_A) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(GNL_A):
	make -C $(GNL_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re:	fclean all

fsan: CFLAGS += $(SANITIZE_FLAGS)
fsan: fclean $(NAME)

.PHONY: all clean fclean re fsan