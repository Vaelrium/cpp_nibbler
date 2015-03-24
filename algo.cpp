//
// algo.cpp for algo in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 14:55:17 2015 Rémi DURAND
// Last update Tue Mar 24 11:22:28 2015 Ambroise Coutarel
//

#include "nibbler.hpp"
#include "./include/IGfxParams.hpp"

int		algo_snake(const int width, const int height, void *handler)
{
  IGfxParams	*displayHandler;
  IGfxParams	*(*butts)();

  (void)width;
  (void)height;
  butts = reinterpret_cast<IGfxParams* (*)()>(dlsym(handler, "mlx_init"));
  if (butts == NULL)
    {
      std::cout << "Yo rrémi" << std::endl;
      std::cout << dlerror() << std::endl;
      return (-1);
    }
  (void)displayHandler;
  displayHandler = butts();
  // jeff = the_creator();
  // jeff->print_name();
  return (0);
}
