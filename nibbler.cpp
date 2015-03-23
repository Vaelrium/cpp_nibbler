//
// nibbler.cpp for nibbler in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 10:40:33 2015 Rémi DURAND
// Last update Mon Mar 23 12:52:24 2015 Rémi DURAND
//

#include "nibbler.hpp"

int		main(int ac, char **av)
{
  int		height;
  int		width;
  std::string	lib;
  void		*handler;

  if (ac != 4)
    {
      std::cout << "Invalid arguments number" << std::endl;
      return (-1);
    }
  width = atoi(av[1]);
  height = atoi(av[2]);
  lib.assign(av[3]);
  if (init_nib(width, height, lib, &handler) == (-1))
    return (0);
  dlclose(handler);
}
