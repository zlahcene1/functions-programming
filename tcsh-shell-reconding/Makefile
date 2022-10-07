##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =			src/my_mysh.c			\
			src/my_cd.c			\
			src/redirect.c			\
			src/setenv_parser.c		\
			src/exec_parser.c		\
			src/my_cmd.c			\
			src/redirect_par2.c		\
			src/my_exec.c			\
			src/ft_word_tab.c		\
			src/check_cmd.c			\
			src/my_un_setenv.c		\
			src/my_setenv.c			\
			src/do_builtin_or_execve.c	\
			src/main.c

OBJ = 		$(SRC:.c=.o)

NAME =		mysh

CFLAGS += 	-I include/ -g3

LIB = 		-L lib -lmy

DONE =		echo -e "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB)
		rm $(OBJ)
		make clean -C lib/my
		$(DONE)

clean :
		make clean -C lib/my
		rm -f $(OBJ) *~
		cd src/ && rm -f $(OBJ) *~

fclean :	clean
		make fclean -C lib/my
		rm -f $(NAME)

re :		$(OBJ)
		make re -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB)
		rm $(OBJ)
		$(DONE)
