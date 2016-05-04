##
## Makefile for makefile in /home/gassem_a/training
##
## Made by aurelien gassemann
## Login   <gassem_a@epitech.net>
##
## Started on  Tue Nov 17 13:16:01 2015 aurelien gassemann
## Last update Sun Dec 20 17:38:40 2015 aurelien gassemann
##

NAME	=	bsq

SRC	=	bsq.c \
		fonctions.c \
		main.c \
		square.c \

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CC	=	gcc

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(SRC)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY:		all clean fclean re
