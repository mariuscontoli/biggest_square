##
## EPITECH PROJECT, 2019
## Makefile my_bsq
## File description:
## Will compile our project
##

NAME 	=	bsq

CC	=	gcc

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -g -g3 -o $(NAME) $(OBJ)

re:
	make fclean
	make all

clean:
	find -name '*.o' -exec rm {} \;

fclean:
	make clean
	rm -f $(NAME)
