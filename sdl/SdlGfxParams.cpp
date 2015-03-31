//
// SdlGfxParams.cpp for  in /home/ganesha/projets/cpp_nibbler/sdl
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 30 14:54:11 2015 Ambroise Coutarel
// Last update Tue Mar 31 12:50:49 2015 Ambroise Coutarel
//

#include "SdlGfxParams.hpp"
#include "../include/nibbler.hpp"
#include <SDL.h>
#include <unistd.h>
#include <iostream>

SdlGfxParams::SdlGfxParams(int win_x, int win_y, leSnake *snek) : IGfxParams(win_x, win_y, snek)
{
}

SdlGfxParams::~SdlGfxParams()
{
}

int	SdlGfxParams::move_snake(char dir, SDL_Surface *window)
{
  if (dir == 1)
    {
      std::cout << "moving right cappn" << std::endl;
      data.snake->setDir(RIGHT_DEC(data.snake->getDir()));
    }
  else if (dir == 2)
    {
      std::cout << "moving left cappn" << std::endl;
      data.snake->setDir(LEFT_INC(data.snake->getDir()));
    }
  // data.snake->move();
  // data.snake->deadCheck(data.win_x / BLOCK_SIZE , data.win_y / BLOCK_SIZE);
  // data.snake->foodCheck(data.win_x / BLOCK_SIZE , data.win_y / BLOCK_SIZE);
  // if (data.snake->getDead())
  //   exit (0);
  drawSnake(window);
  return (0);
}

int		SdlGfxParams::SdlKeyEvents(SDL_Event *event, SDL_Surface *window)
{
  if (event->key.keysym.sym == SDLK_ESCAPE)
    exit(0);
  else if (event->key.keysym.sym == SDLK_LEFT)
    move_snake(1, window);
  else if (event->key.keysym.sym == SDLK_RIGHT)
    move_snake(2, window);
  return (0);
}

int		SdlGfxParams::sdlWait(SDL_Surface *window)
{
  SDL_Event	event;

  while (data.snake->getDead() != false)
    {
      data.snake->move();
      data.snake->deadCheck(data.win_x / BLOCK_SIZE, data.win_y / BLOCK_SIZE);
      data.snake->foodCheck(data.win_x / BLOCK_SIZE, data.win_y / BLOCK_SIZE);
      drawSnake(window);
      if (SDL_PollEvent(&event))
	{
	  if (event.type == SDL_QUIT)
	    return (0);
	  else if (event.type == SDL_KEYDOWN)
	    SdlKeyEvents(&event, window);
	}
      usleep(100000);
    }
  return (0);
}

int		SdlGfxParams::drawSnake(SDL_Surface *window)
{
  SDL_Rect	temp_rect;

  SDL_FillRect(window, NULL, GROUND);
  temp_rect.x = data.snake->leFood.first * BLOCK_SIZE;
  temp_rect.y = data.snake->leFood.second * BLOCK_SIZE;
  temp_rect.w = BLOCK_SIZE;
  temp_rect.h = BLOCK_SIZE;
  SDL_FillRect(window, &temp_rect, FOOD);
  temp_rect.x = data.snake->getHx() * BLOCK_SIZE;
  temp_rect.y = data.snake->getHy() * BLOCK_SIZE;
  SDL_FillRect(window, &temp_rect, SNEKHEAD);
  for(bodyVector::const_iterator it = data.snake->body.begin(); it != data.snake->body.end(); ++it)
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
  drawSnake(window);
  sdlWait(window);
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
