//
// init.cpp for init in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 11:16:54 2015 Rémi DURAND
// Last update Mon Mar 23 12:20:12 2015 Rémi DURAND
//

#include "nibbler.hpp"

int		init_nib(int width, int height, std::string lib)
{
  if (width <= 4 || height <= 4 || (height * width) < 40)
    {
      std::cout << "Area must at least have 40 blocks" << std::endl;
      return (-1);
    }
  return (0);
}
