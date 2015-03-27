##
## Makefile for  in /home/ganesha/projets/cpp_nibbler/sdl
##
## Made by Ambroise Coutarel
## Login   <ganesha@epitech.net>
##
## Started on  Thu Mar 26 13:55:02 2015 Ambroise Coutarel
## Last update Thu Mar 26 13:59:30 2015 Ambroise Coutarel
##

CC	= 	gcc

NAME	= 	lib_nibbler_sdl.so


SRC	=

OBJ	= $(SRC:.cpp=.o)

CXXFLAGS= -I/usr/X11R6/include -O3 -fPIC -Wno-write-strings

$(NAME):         $(OBJ)
	 	$(CC) -rdynamic -shared -o $(NAME) $(OBJ)
	 	cp $(NAME) ..

clean	:
	rm -f $(OBJ)

fclean	:
	rm -f $(NAME)

re: fclean all
