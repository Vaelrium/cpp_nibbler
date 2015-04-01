##
## Makefile for make in /home/durand_u/github/cpp_nibbler/ncurses
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Mon Mar 30 14:39:46 2015 Rémi DURAND
## Last update Wed Apr  1 15:57:41 2015 Rémi DURAND
##

CC      =       gcc

NAME    =       lib_nibbler_ncurses.so

SRC     =       ncurses_snake_init.cpp	\
		NcurGfxParams.cpp	\
                leSnake.cpp

OBJ =   $(SRC:.cpp=.o)

CXXFLAGS= -O3 -fPIC -Wno-write-strings -L./

$(NAME): $(OBJ)
		$(CC) -rdynamic -shared -lncurses -o $(NAME) $(OBJ) -L./
		cp $(NAME) ..

clean:
	rm -f $(OBJ) *~ core *.core

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
