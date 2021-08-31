##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC     =		main.c				\
				ncurses/game.c		\
				ncurses/hangman.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       ./hangman

CFLAGS	+=		-I ./include

all:    $(NAME)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
