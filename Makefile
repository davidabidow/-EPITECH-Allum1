##
## Makefile for Makefile in /home/tran_0/rendu/CPE_2013_allum1
## 
## Made by david tran
## Login   <tran_0@epitech.net>
## 
## Started on  Fri Jan 31 10:35:33 2014 david tran
## Last update Mon Feb 10 11:18:45 2014 david tran
##

RM	= rm -f

SRCS	= allum1.c \
	  my_putstr.c \
	  my_strdup.c \
	  calclines.c \
	  my_getnbr.c \
	  initstruct.c \
	  afffile.c \
	  my_put_nbr.c \
	  makeread.c \
	  presskeys.c \
	  otherkeys.c \
	  finishfeed.c \
	  doia.c \
	  checkwinsize.c \

OBJ	= $(SRCS:.c=.o)

NAME	= allum1

CFLAGS	= -W -Werror -Wall -Wextra

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
