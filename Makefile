# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 11:55:44 by nbjaghou          #+#    #+#              #
#    Updated: 2019/11/16 16:24:02 by nbjaghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c basic_function1.c basic_function2.c display_flag.c flags.c \
ft_adress.c ft_adress2.c ft_char.c ft_hexlow.c ft_hexlow2.c ft_hexup.c \
ft_hexup2.c ft_int.c ft_int2.c ft_string.c ft_string2.c ft_unsigned.c \
ft_unsigned2.c display_flag2.c display_flag3.c help_func.c \
libft/free_str.c libft/ft_hex_len.c libft/ft_long_len.c libft/ft_numberlen.c \
libft/ft_putchar.c libft/ft_putnbr.c libft/ft_putnbr_unsigned.c \
libft/ft_putstr.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_unsigned_len.c\
libft/nb_point_count.c\

OBJ = ft_printf.o basic_function1.o basic_function2.o display_flag.o flags.o \
ft_adress.o ft_adress2.o ft_char.o ft_hexlow.o ft_hexlow2.o ft_hexup.o \
ft_hexup2.o ft_int.o ft_int2.o ft_string.o ft_string2.o ft_unsigned.o \
ft_unsigned2.o display_flag2.o display_flag3.o help_func.o \
free_str.o ft_hex_len.o ft_long_len.o ft_numberlen.o \
ft_putchar.o ft_putnbr.o ft_putnbr_unsigned.o \
ft_putstr.o ft_strdup.o ft_strlen.o ft_unsigned_len.o nb_point_count.o\

all : $(NAME)

$(NAME) :
	gcc -c $(SRC) -Wall -Wextra -Werror
	ar -rc $(NAME) $(OBJ)

clean : 
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
