##
## Makefile for MiniLibX in /home/JEFF/
##
## Made by Jeff Lavariable
## Login   <jeff@epitech.net>
##
## Started on  Tue Oct  5 15:56:43 2228 Jeff Lavariable
## Last update Mon Mar 30 15:19:29 2015 Ambroise Coutarel
##


CC	= 	gcc

NAME	= 	lib_nibbler_mlx.so

SRC	=	mlx_snake_init.cpp		\
		MlxGfxParams.cpp		\
		../IGfxParams.cpp		\
		leSnake.cpp

OBJ =	$(SRC:.cpp=.o)

CXXFLAGS= -I/usr/X11R6/include -O3 -fPIC -Wno-write-strings -L./ -lmlx -lX11 -lXext

$(NAME):         $(OBJ)
	 	$(CC) -rdynamic -shared -o $(NAME) $(OBJ) -L./ -lmlx -lX11 -lXext
	 	cp $(NAME) ..

clean	:
	rm -f $(OBJ) *~ core *.core

fclean	: clean
	 rm -f $(NAME)

re: fclean $(NAME)
