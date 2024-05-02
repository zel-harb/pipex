CC = cc
NAME = pipex
FLAGS = -Wall -Wextra -Werror 
SOURCES = main.c \
		  check.c \
		  utils.c \
		  split.c \
		  funct.c 

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean :
		rm -rf $(OBJECTS)
fclean : clean
		rm -rf $(NAME)
re :fclean all