# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:55:57 by minjkim2          #+#    #+#              #
#    Updated: 2021/06/07 18:55:58 by minjkim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c flag.c width.c utils.c
#BONUS_SRCS =
#BONUS_OBJS = $(BONUS_SRCS:.c=.o)
#INCS = libft.h
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

#bonus : $(OBJS) $(BONUS_OBJS)
#	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re
