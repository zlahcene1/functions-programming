##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =		src/prints/other_prints.c	\
		src/prints/bases_prints.c	\
		src/flag_finder.c		\
		src/core_function.c

OBJ = 		$(SRC:.c=.o)

NAME =		libmy.a

CFLAGS += 	-I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		rm $(OBJ)
clean :
		rm -f $(OBJ) *~
		cd src/ && rm -f $(OBJ) *~

fclean :	clean
		rm -f $(NAME)

re :		$(OBJ)
