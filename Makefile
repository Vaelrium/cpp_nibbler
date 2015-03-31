##
## Makefile for Makefile in /home/durand_u/github/cpp_nibbler
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Mon Mar 23 10:46:23 2015 Rémi DURAND
## Last update Tue Mar 31 10:31:59 2015 Ambroise Coutarel
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

MLX_LIB		=	lib_nibbler_mlx.so

SDL_LIB		=	lib_nibbler_sdl.so

CXXFLAGS	+=	-W -Wall -Wextra -Werror -ldl

DEBUG		+=	-g3

all: $(NAME) mlx sdl

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(DEBUG)

mlx:
	$(MAKE) -C $(MLX)

sdl:
	$(MAKE) -C $(SDL)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)
	$(MAKE) clean -C $(SDL)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB)
	$(RM) $(SDL_LIB)

re: fclean all
