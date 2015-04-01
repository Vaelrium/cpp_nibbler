##
## Makefile for  in /home/ganesha/projets/cpp_nibbler/sdl
##
## Made by Ambroise Coutarel
## Login   <ganesha@epitech.net>
##
## Started on  Thu Mar 26 13:55:02 2015 Ambroise Coutarel
## Last update Wed Apr  1 12:06:33 2015 Ambroise Coutarel
##

CC	= 	gcc

NAME	= 	lib_nibbler_sfml.so


SRC	=	SfmlGfxParams.cpp	\
		../IGfxParams.cpp	\
		leSnake.cpp

OBJ	= $(SRC:.cpp=.o)

CXXFLAGS=  -O3 -fPIC -Wno-write-strings -lsfml-system -lsfml-window -lsfml-graphics

all:		$(NAME)

$(NAME):         $(OBJ)
	 	$(CC) -rdynamic -I /usr/include/SDL -shared -o $(NAME) $(OBJ) -lsfml-system -lsfml-window -lsfml-graphics
	 	cp $(NAME) ..

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re: fclean all
