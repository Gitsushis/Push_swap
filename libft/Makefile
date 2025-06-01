# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 13:06:58 by cbouyer           #+#    #+#              #
#    Updated: 2025/06/01 18:52:30 by candrabouye      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library    = libft

files    = ft_atoi \
                    ft_bzero \
                    ft_calloc \
                    ft_isalnum \
                    ft_isalpha \
                    ft_isascii \
                    ft_isdigit \
                    ft_isprint \
                    ft_itoa \
                    ft_memchr \
                    ft_memcmp \
                    ft_memcpy \
                    ft_memmove \
                    ft_memset \
                    ft_putchar_fd \
                    ft_putendl_fd \
                    ft_putnbr_fd \
                    ft_putstr_fd \
                    ft_split \
                    ft_strchr \
                    ft_strdup \
                    ft_striteri \
                    ft_strjoin \
                    ft_strlcat \
                    ft_strlcpy \
                    ft_strlen \
                    ft_strmapi \
                    ft_strncmp \
                    ft_strnstr \
                    ft_strrchr \
                    ft_strtrim \
                    ft_substr \
                    ft_tolower \
                    ft_toupper \

BONUS_files = ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \

NAME = libft.a

CC    = cc

CmpFlags    = -Wall -Wextra -Werror

#can use src/%.c if addprefix isnt allowed, it allows us to find the path of all c files
CFILES = $(files:%=%.c)

OFILES = $(files:%=%.o)

CFILES_BONUS = $(BONUS_files:%=%.c)

OFILES_BONUS = $(BONUS_files:%=%.o)

OUTN = $(NAME)

$(NAME):
		$(CC) $(CmpFlags) -Iinclude -c $(addprefix src/, $(CFILES)) 
		ar -rc $(OUTN) $(OFILES)

bonus :
		$(CC) $(CmpFlags) -c $(CFILES_BONUS) -I./include
		ar -rc $(OUTN) $(OFILES_BONUS) 

#in order to include the h file of thats in a different folder, use -Iinclude, or -I./include/filename
# addprefix src/, $(VARIABLE) is used to find the cfiles in another folder

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)
	rm -f $(OFILES_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
