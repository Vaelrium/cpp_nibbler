##
## Makefile for Makefile in /home/durand_u/github/cpp_nibbler
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Mon Mar 23 10:46:23 2015 Rémi DURAND
## Last update Mon Mar 23 14:44:03 2015 Ambroise Coutarel
##

SRC		=	nibbler.cpp	\
			init.cpp

CC		=	g++

RM		=	rm -f

OBJ		=	$(SRC:.cpp=.o)

NAME		=	nibbler

MLX		=	./minilibx/

MLX_LIB		=	lib_nibbler_mlx.so

CXXFLAGS	+=	-W -Wall -Wextra -Werror -ldl

all: $(NAME) mlx

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

mlx:
	$(MAKE) -C $(MLX)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB)

re: fclean all
