##
## Makefile for  in /home/ganesha/projets/cpp_nibbler/sdl
##
## Made by Ambroise Coutarel
## Login   <ganesha@epitech.net>
##
## Started on  Thu Mar 26 13:55:02 2015 Ambroise Coutarel
## Last update Tue Mar 31 11:14:37 2015 Ambroise Coutarel
##

CC	= 	gcc

NAME	= 	lib_nibbler_sdl.so


SRC	=	SdlGfxParams.cpp	\
		../IGfxParams.cpp	\
		leSnake.cpp

OBJ	= $(SRC:.cpp=.o)

CXXFLAGS=  -O3 -fPIC -Wno-write-strings -I/usr/include/SDL -D_GNU_SOURCE=1 -lSDL

all:		$(NAME)

$(NAME):         $(OBJ)
	 	$(CC) -rdynamic -I /usr/include/SDL -shared -o $(NAME) $(OBJ) -lSDL
	 	cp $(NAME) ..

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re: fclean all
