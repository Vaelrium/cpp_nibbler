//
// algo.cpp for algo in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 14:55:17 2015 Rémi DURAND
// Last update Tue Mar 24 13:32:05 2015 Rémi DURAND
//

#include "nibbler.hpp"
#include "./include/IGfxParams.hpp"

int		algo_snake(const int width, const int height, void *handler)
{
  IGfxParams	*displayHandler;
  IGfxParams	*(*genitor3000)(int, int);

  genitor3000 = reinterpret_cast<IGfxParams* (*)(int, int)>(dlsym(handler, "init_lib"));
  if (genitor3000 == NULL)
    {
      std::cout << dlerror() << std::endl;
      return (-1);
    }
  displayHandler = genitor3000(width, height);
  (void)displayHandler;
  return (0);
}
