# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:55:57 by minjkim2          #+#    #+#              #
#    Updated: 2021/06/08 12:43:03 by minjkim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_check_format.c ft_get_format.c \
ft_type.c ft_type2.c ft_typed_utils.c ft_typep_utils.c ft_memory.c \
ft_utils.c ft_utils2.c ft_utils3.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

bonus : all

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re
