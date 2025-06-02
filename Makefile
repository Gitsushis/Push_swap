# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 20:14:16 by candrabouye       #+#    #+#              #
#    Updated: 2025/06/01 20:49:59 by candrabouye      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_NAME = push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build object directory and compile .c files to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build static library push_swap.a
$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

# Build executable push_swap
$(NAME): $(LIBFT) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(LIB_NAME) $(LIBFT)

# Default rule: build everything
all: $(LIBFT) $(LIB_NAME) $(NAME)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME) $(LIB_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
