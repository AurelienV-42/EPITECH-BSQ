##
## EPITECH PROJECT, 2017
## Aurélien Vandaële <aurelien.vandaele@epitech.eu>
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/bsq.c		\
		src/count.c		\
		src/algo/find_square.c	\
		src/algo/fill_array_nb.c\
		src/map_test.c

NAME	=	bsq

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-lmy -Llib/my

CFLAGS	=	-W -Wall -Werror -Wextra -I include/ -g

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)
		make clean

clean:
		rm -f $(OBJ) *~ src/*~ lib/*~ lib/my/*~ include/*~ vgcore*

fclean:		clean
		make fclean -C lib/my
		rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean
