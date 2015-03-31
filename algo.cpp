//
// algo.cpp for algo in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 14:55:17 2015 Rémi DURAND
// Last update Tue Mar 31 15:03:44 2015 Rémi DURAND
//

#include <unistd.h>
#include "./include/leSnake.hpp"
#include "./include/nibbler.hpp"
#include "./include/IGfxParams.hpp"

int		algo_snake(const int width, const int height, void *handler)
{
  IGfxParams	*displayHandler;
  IGfxParams	*(*genitor3000)(int, int, leSnake*);
  leSnake	snake(width, height);

  genitor3000 = reinterpret_cast<IGfxParams* (*)(int, int, leSnake*)>(dlsym(handler, "init_lib"));
  if (genitor3000 == NULL)
    {
      std::cout << dlerror() << std::endl;
      return (-1);
    }
  displayHandler = genitor3000(width * BLOCK_SIZE, height * BLOCK_SIZE, &snake);
  displayHandler->gameLoop();
  if (snake.getDead() == true)
    std::cout << "You're dead" << std::endl;
  else
    std::cout << "Leaving the game" << std::endl;
  return (0);
}
