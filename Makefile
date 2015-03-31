##
## Makefile for Makefile in /home/durand_u/github/cpp_nibbler
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Mon Mar 23 10:46:23 2015 Rémi DURAND
## Last update Tue Mar 31 13:49:59 2015 Rémi DURAND
##

SRC		=	nibbler.cpp	\
			init.cpp	\
			algo.cpp	\
			leSnake.cpp

CC		=	g++

RM		=	rm -f

OBJ		=	$(SRC:.cpp=.o)

NAME		=	nibbler

MLX		=	./minilibx/

SDL		=	./sdl/

NCURS		=	./ncurses/

MLX_LIB		=	lib_nibbler_mlx.so

SDL_LIB		=	lib_nibbler_sdl.so

NCURS_LIB	=	lib_ncurses.so

CXXFLAGS	+=	-W -Wall -Wextra -Werror -ldl

DEBUG		+=	-g3

all: $(NAME) mlx sdl ncurs

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(DEBUG)

mlx:
	$(MAKE) -C $(MLX)

sdl:
	$(MAKE) -C $(SDL)

ncurs:
	$(MAKE) -C $(NCURS)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)
	$(MAKE) clean -C $(SDL)
	$(MAKE) clean -C $(NCURS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB)
	$(RM) $(SDL_LIB)
	$(RM) $(NCURS_LIB)

re: fclean all
