SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -I ./

NAME =	libmy_malloc.so

CFLAGS = -Wall -Wextra -fPIC -g3

CC = gcc
all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -fPIC -shared -o $(NAME) $(OBJ) $(CFLAGS)

clean:

	rm -f $(OBJ)

fclean: clean

	rm -f $(NAME)
	rm -f *.c~


re:	fclean all
