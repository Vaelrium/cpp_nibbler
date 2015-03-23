##
## Makefile for Makefile in /home/durand_u/github/cpp_nibbler
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Mon Mar 23 10:46:23 2015 Rémi DURAND
## Last update Mon Mar 23 10:47:46 2015 Rémi DURAND
##

SRC		=	nibbler.cpp

CC		=	g++

RM		=	rm -f

OBJ		=	$(SRC:.cpp=.o)

NAME		=	nibbler

CXXFLAGS	+=	-W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
