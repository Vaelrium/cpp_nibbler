//
// SdlGfxParams.cpp for  in /home/ganesha/projets/cpp_nibbler/sdl
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 30 14:54:11 2015 Ambroise Coutarel
// Last update Tue Mar 31 11:17:49 2015 Ambroise Coutarel
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

int		SdlGfxParams::drawSnake(SDL_Surface *window, dump *data)
{
  SDL_Rect	temp_rect;

  SDL_FillRect(window, NULL, GROUND);
  temp_rect.x = data->snake->leFood.first * BLOCK_SIZE;
  temp_rect.y = data->snake->leFood.second * BLOCK_SIZE;
  temp_rect.w = BLOCK_SIZE;
  temp_rect.h = BLOCK_SIZE;
  SDL_FillRect(window, &temp_rect, FOOD);
  temp_rect.x = data->snake->getHx() * BLOCK_SIZE;
  temp_rect.y = data->snake->getHy() * BLOCK_SIZE;
  SDL_FillRect(window, &temp_rect, SNEKHEAD);
  for(bodyVector::const_iterator it = data->snake->body.begin(); it != data->snake->body.end(); ++it)
    {
      temp_rect.x = it->first * BLOCK_SIZE;
      temp_rect.y = it->second * BLOCK_SIZE;
      SDL_FillRect(window, &temp_rect, SNEKBOD);
    }
  SDL_Flip(window);
  return (0);
}

int		SdlGfxParams::gameLoop()
{
  SDL_Surface	*window;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("KoujouSnake", NULL);
  window = SDL_SetVideoMode(data.win_x, data.win_y, 32, SDL_SWSURFACE);
  drawSnake(window, &(this->data));
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
