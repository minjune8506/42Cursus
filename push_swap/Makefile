# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 15:22:50 by minjune           #+#    #+#              #
#    Updated: 2021/08/07 14:41:52 by minjkim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

CHECKER_HEADERS_LIST = checker.h
CHECKER_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(CHECKER_HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = push_swap.c\
		stack_init.c\
		stack_utils.c\
		check.c\
		utils.c\
		parse.c\
		sort_utils.c\
		sort_utils2.c\
		sort_utils3.c \
		get_mid.c\
		sort_a.c\
		sort_b.c\
		small_sort.c\
		small_count_sort.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

CHECKER_DIRECTORY = ./checker_srcs/
CHECKER_SRCS_LIST = checker.c\
					stack_init.c\
					parse.c\
					check.c\
					utils.c\
					stack_utils.c\
					get_next_line_bonus.c\
					get_next_line_utils_bonus.c\
					sort_utils.c\
					sort_utils2.c\
					sort_utils3.c
CHECKER_SRCS = $(addprefix $(CHECKER_DIRECTORY), $(CHECKER_SRCS_LIST))

CHECKER_OBJS_DIR = ./checker_objects/
CHECKER_OBJS_LIST = $(patsubst %.c, %.o, $(CHECKER_SRCS_LIST))
CHECKER_OBJS = $(addprefix $(CHECKER_OBJS_DIR), $(CHECKER_OBJS_LIST))

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME) $(CHECKER)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(BLUE)$(NAME) : object files created$(RESET)"
	@echo "$(BLUE)$(NAME) : $(NAME) created$(RESET)"

$(CHECKER) : $(CHECKER_OBJS_DIR) $(CHECKER_OBJS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(CHECKER_OBJS) -o $(CHECKER)
	@echo "\n$(BLUE)$(CHECKER) : $(CHECKER) created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(BLUE)$(NAME) : $(OBJECTS_DIRECTORY) created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(BLUE).$(RESET)\c"

$(CHECKER_OBJS_DIR):
	@mkdir -p $(CHECKER_OBJS_DIR)
	@echo "$(BLUE)$(CHECKER) : $(CHECKER_OBJS_DIR) created $(RESET)"

$(CHECKER_OBJS_DIR)%.o : $(CHECKER_DIRECTORY)%.c $(CHECKER_HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(BLUE).$(RESET)\c"
	   
$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(BLUE)$(NAME) : $(LIBFT) created$(RESET)"

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@echo "$(RED)$(NAME) : object files deleted$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED)$(NAME) : $(OBJECTS_DIRECTORY) deleted$(RESET)"
	@rm -rf $(CHECKER_OBJS_DIR)
	@echo "$(RED)$(CHECKER) : $(CHECKER_OBJS_DIR) deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)$(NAME) : $(LIBFT) deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) : $(NAME) deleted$(RESET)"
	@rm -f $(CHECKER)
	@echo "$(RED)$(CHECKER) : $(CHECKER) deleted$(RESET)"
re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
