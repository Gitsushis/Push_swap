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

NAME = push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Build object directory and compile each .c file into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library archive from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Default rule
all: $(NAME)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything including library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
