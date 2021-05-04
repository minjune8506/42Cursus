CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = a.out
SRCS = ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c main.c
OBJS = ft_toupper.o ft_tolower.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.c main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ 

clean :
	rm $(OBJS)

fclean : clean
	rm $(TARGET)
