##
## Makefile for MiniLibX in /home/JEFF/
##
## Made by Jeff Lavariable
## Login   <jeff@epitech.net>
##
## Started on  Tue Oct  5 15:56:43 2228 Jeff Lavariable
## Last update Fri Mar 27 11:27:49 2015 Ambroise Coutarel
##


CC	= 	gcc

NAME	= 	lib_nibbler_mlx.so

TEST	=	mlx_snake_init.cpp		\
		MlxGfxParams.cpp		\
		mlx_key_events.cpp		\
		../IGfxParams.cpp

OBJ_CPP = $(TEST:.cpp=.o)

CXXFLAGS= -I/usr/X11R6/include -O3 -fPIC -Wno-write-strings -L./ -lmlx -lX11 -lXext

$(NAME):         $(OBJ_CPP)
	 	$(CC) -rdynamic -shared -o $(NAME) $(OBJ_CPP) -L./ -lmlx -lX11 -lXext
	 	cp $(NAME) ..

clean	:
	rm -f $(OBJ) $(OBJ_CPP) $(NAME) *~ core *.core

re: clean $(NAME)
