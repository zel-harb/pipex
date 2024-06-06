CC = cc
NAME = pipex
BNAME = pipex_bonus
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
SOURCES = ./mandatory/main.c \
		  ./mandatory/check.c \
		  ./mandatory/utils.c \
		  ./mandatory/split.c \
		  ./mandatory/split2.c \
		  ./mandatory/funct.c \
		  ./mandatory/funct2.c \
		  ./mandatory/utils2.c \
		  ./mandatory/cmd.c \
		  ./mandatory/help.c 

BSOURCES = 	./bonus/main_bonus.c \
			./bonus/check_bonus.c \
		  	./bonus/utils_bonus.c \
		  	./bonus/split_bonus.c \
		  	./bonus/funct_bonus.c \
		 	./bonus/funct2_bonus.c \
		  	./bonus/utils2_bonus.c \
		  	./bonus/cmd.c			\
		  	./bonus/cmd_null.c	\
		 	./bonus/get_next_line.c \
		  	./bonus/get_next_line_use.c \
		  	./bonus/here_doc.c	\
		  	./bonus/pipe.c \
		 	./bonus/here_doc_null.c \
		  	./bonus/cmd_exp.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
bonus : $(BOBJECTS)
	$(CC) $(FLAGS)  $(BOBJECTS)  -o $(BNAME)
clean :
		rm -rf $(OBJECTS) $(BOBJECTS)
fclean : clean
		rm -rf $(NAME) $(BNAME)
re :fclean all