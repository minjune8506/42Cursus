# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:55:57 by minjkim2          #+#    #+#              #
#    Updated: 2021/06/08 09:13:13 by minjkim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OUT = a.out
#a.out
#libftprintf.a
SRCS = ft_printf.c flag.c width.c utils.c dot.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)
	$(CC) $(FLAGS) -o $(OUT) $(OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)

re : fclean all

.PHONY : bonus all clean fclean re
