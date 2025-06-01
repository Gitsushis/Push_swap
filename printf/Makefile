# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 17:20:43 by cbouyer           #+#    #+#              #
#    Updated: 2025/01/16 18:46:43 by cbouyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

library = libftprintf

files = ft_print_hex \
        ft_print_ptr \
        ft_printf \
        ft_printnbr \
        ft_printpercent \
        ft_printstr \
        ft_unsigned \

Compiler	= gcc

CmpFlags	= -Wall -Wextra -Werror

NAME = libftprintf.a

CFILES = $(files:%=%.c)

OFILES = $(files:%=%.o)

OUTN = $(NAME)

$(NAME) : 
	$(Compiler) $(Cmpflags) -c $(addprefix src/, $(CFILES)) -I./include
	ar -rc $(OUTN) $(OFILES)

all : $(NAME)

clean :
	rm -f $(NAME)
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
