//
// algo.cpp for algo in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 14:55:17 2015 Rémi DURAND
// Last update Wed Mar 25 13:08:31 2015 Rémi DURAND
//

#include <unistd.h>
#include "./include/leSnake.hpp"
#include "nibbler.hpp"
#include "./include/IGfxParams.hpp"

int		game_launch(const int width, const int height, void *handler)
{
  leSnake	snake(width, height);

  while (snake.getDead() == false)
    {
      snake.move();
      snake.deadCheck(width, height);
      snake.foodCheck(width, height);
      //affichage
      usleep(500000);
    }
  (void)handler;
  return (0);
}

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
  displayHandler = genitor3000(width * BLOCK_SIZE, height * BLOCK_SIZE);
  (void)displayHandler;
  game_launch(width, height, handler);
  return (0);
}
