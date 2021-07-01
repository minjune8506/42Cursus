# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:55:57 by minjkim2          #+#    #+#              #
#    Updated: 2021/06/15 12:45:12 by minjune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = ./srcs/ft_split.c ./srcs/ft_strjoin.c \
./srcs/pipex.c ./srcs/cmd.c ./srcs/redirect.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = ./bonus_srcs/cmd_bonus.c ./bonus_srcs/pipex_bonus.c ./bonus_srcs/redirect_bonus.c \
./bonus_srcs/here_doc_bonus.c \
./bonus_srcs/libft/ft_split_bonus.c ./bonus_srcs/libft/ft_strjoin_bonus.c ./bonus_srcs/libft/utils_bonus.c\
./bonus_srcs/get_next_line/get_next_line_bonus.c ./bonus_srcs/get_next_line/get_next_line_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
all : $(NAME)

.c.o :
	$(CC) $(FLAGS) -c $< -o $@ -I ./includes
	
$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

bonus : $(BONUS_OBJS)
	rm -f $(NAME)
	$(CC) $(FLAGS) -o $(NAME) $(BONUS_OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re
