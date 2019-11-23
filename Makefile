##
## EPITECH PROJECT, 2019
## Makefile my_bsq
## File description:
## Will compile our project
##

CC	=	gcc

NAME 	=	bsq

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	$(CC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
