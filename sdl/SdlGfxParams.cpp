//
// SdlGfxParams.cpp for  in /home/ganesha/projets/cpp_nibbler/sdl
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 30 14:54:11 2015 Ambroise Coutarel
// Last update Tue Mar 31 10:38:29 2015 Ambroise Coutarel
//

#include "SdlGfxParams.hpp"
#include "../include/nibbler.hpp"
#include <SDL.h>
#include <iostream>

SdlGfxParams::SdlGfxParams(int win_x, int win_y, leSnake *snek) : IGfxParams(win_x, win_y, snek)
{
}

SdlGfxParams::~SdlGfxParams()
{
}

int		SdlGfxParams::sdlWait()
{
  //char		running = 1;
  SDL_Event	event;

  while ("jeff")
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	return (0);
    }
  return (0);
}

int		SdlGfxParams::drawSnake(SDL_Surface *window)
{
  SDL_Rect	temp_rect;

  std::cout << "blitting BG" << std::endl;
  SDL_FillRect(window, NULL, GROUND);
  SDL_Flip(window);
  temp_rect.x = this->data.snake->leFood.first * BLOCK_SIZE;
  temp_rect.y = this->data.snake->leFood.second * BLOCK_SIZE;
  temp_rect.w = BLOCK_SIZE;
  temp_rect.h = BLOCK_SIZE;
  std::cout << "blitting food" << std::endl;
  std::cout << temp_rect.x << std::endl;
  std::cout << temp_rect.y << std::endl;
  SDL_FillRect(window, &temp_rect, FOOD);
  temp_rect.x = this->data.snake->getHx() * BLOCK_SIZE;
  temp_rect.y = this->data.snake->getHy() * BLOCK_SIZE;
  std::cout << "blitting head" << std::endl;
  std::cout << temp_rect.x << std::endl;
  std::cout << temp_rect.y << std::endl;
  SDL_FillRect(window, &temp_rect, SNEKHEAD);
  // for(bodyVector::const_iterator it = data.snake->body.begin(); it != data.snake->body.end(); ++it)
  //   {
  //     temp_rect.x = it->first * BLOCK_SIZE;
  //     temp_rect.y = it->second * BLOCK_SIZE;
  //     std::cout << "blitting body" << std::endl;
  //     SDL_FillRect(window, &temp_rect, SNEKBOD);
  //     //drawSquare(it->first * BLOCK_SIZE, it->second * BLOCK_SIZE, data, SNEKBOD);
  //   }
  SDL_Flip(window);
  return (0);
}

int		SdlGfxParams::gameLoop()
{
  SDL_Surface	*window;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("KoujouSnake", NULL);
  window = SDL_SetVideoMode(data.win_x, data.win_y, 32, SDL_SWSURFACE);
  std::cout << data.win_x << std::endl;
  std::cout << data.win_y << std::endl;
  drawSnake(window);
  sdlWait();
  SDL_Quit();
  return (0);
}

extern "C"
{
  IGfxParams	*init_lib(int win_x, int win_y, leSnake *snek)
  {
    return (new SdlGfxParams(win_x, win_y, snek));
  }
}
