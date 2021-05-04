CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = a.out
SRCS = ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c main.c
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

.c.o :
	$(CC) $(FLAGS) -c $< -o $@
	
$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ 

clean :
	rm $(OBJS)

fclean : clean
	rm $(TARGET)
