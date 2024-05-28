CC = cc
NAME = pipex
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
SOURCES = main_bonus.c \
		  check_bonus.c \
		  utils_bonus.c \
		  split_bonus.c \
		  funct_bonus.c \
		  funct2_bonus.c \
		  utils2_bonus.c \
		  cmd.c			\
		  cmd_null.c	\
		  get_next_line.c \
		  get_next_line_use.c \
		  here_doc.c	\
		  pipe.c \
		  here_doc_null.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean :
		rm -rf $(OBJECTS)
fclean : clean
		rm -rf $(NAME)
re :fclean all