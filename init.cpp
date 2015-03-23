//
// init.cpp for init in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 11:16:54 2015 Rémi DURAND
// Last update Mon Mar 23 15:00:21 2015 Rémi DURAND
//

#include "nibbler.hpp"

int		init_nib(const int width, const int height,
			 std::string lib, void **handler)
{
  if (width < 4 || width > 10 || height < 4 || height > 10 || (height * width) < 40)
    {
      std::cout << "Area must have [40-100] blocks" << std::endl;
      return (-1);
    }
  lib = "./" + lib;
  *handler = dlopen(lib.c_str(), RTLD_LAZY);
  if (*handler == NULL)
    {
      std::cout << dlerror() << std::endl;
      return (-1);
    }
  return (0);
}
