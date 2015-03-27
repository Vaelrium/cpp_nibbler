//
// MlxGfxParams.cpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:40:15 2015 Ambroise Coutarel
// Last update Fri Mar 27 15:49:04 2015 Ambroise Coutarel
//

extern "C"
{
#include "mlx.h"
}
#include "../include/nibbler.hpp"
#include "MlxGfxParams.hpp"
#include <cstdlib>
#include <iostream>
extern "C"
{
  void	*mlx_init();
}

MlxGfxParams::MlxGfxParams(int win_x, int win_y, leSnake *snek) : IGfxParams(win_x, win_y, snek)
{
  this->data.win_x = win_x;
  this->data.win_y = win_y;
  this->data.mlx_ptr = mlx_init();
  this->data.win_ptr = mlx_new_window(this->data.mlx_ptr, win_x, win_y, "koujouSnake");
  this->data.img_ptr = mlx_new_image(this->data.mlx_ptr, win_x, win_y);
  this->data.img = mlx_get_data_addr(this->data.img_ptr, &(this->data.bpp),
				&(this->data.sizeline), &(this->data.endian));
  this->data.snake = snek;
}

MlxGfxParams::~MlxGfxParams()
{
}

int	MlxGfxParams::drawSquare(int sq_x, int sq_y, dump *data, int color)
{
  int x = 0, y = 0;

  while (y != BLOCK_SIZE)
    {
      while (x != BLOCK_SIZE)
  	{
	  my_pixel_put_to_image((sq_x + x), (sq_y + y), data, color);
  	  ++x;
  	}
      ++y;
      x = 0;
    }
  return (0);
}

#include <cstdio>

int	MlxGfxParams::drawSnake(dump *data)
{
  drawSquare(50, 50, data, FOOD);
  drawSquare(70, 50, data, FOOD);
  printf("SNEKHEAD : x = %d, y = %d\n", data->snake->leFood.first, data->snake->leFood.second);
  // std::cout << "DRAWING FüD\n" << std::endl;
  // std::cout << "food x : " << data->snake->leFood.first << std::endl;
  // drawSquare(data->snake->leFood.first * BLOCK_SIZE, data->snake->leFood.second * BLOCK_SIZE, data, FOOD);
  // std::cout << "DRAWING SNEKHED\n" << std::endl;
  // drawSquare(data->snake->getHx() * BLOCK_SIZE, data->snake->getHy() * BLOCK_SIZE, data, SNEKHEAD);
  // for(bodyVector::const_iterator it = data->snake->body.begin(); it != data->snake->body.end(); ++it) {
  //   drawSquare(it->first * BLOCK_SIZE, it->second * BLOCK_SIZE, data, SNEKBOD);
  // }
  return 0;
}

int	MlxGfxParams::updateImg(dump *data)
{
  int	x = 0, y = 0;

  while (y != data->win_y)
    {
      while (x != data->win_x)
  	{
	  my_pixel_put_to_image(x, y, data, GROUND);
  	  ++x;
  	}
      ++y;
      x = 0;
    }
  drawSnake(data);
  return (0);
}

int	MlxGfxParams::move_snake(char dir, dump *data)
{
  if (dir)
    data->snake->setDir(RIGHT_DEC(data->snake->getDir()));
  else
    data->snake->setDir(LEFT_INC(data->snake->getDir()));
  updateImg(data);
  expose_redraw(data);
  return (0);
}

int	MlxGfxParams::key_event(int keycode, void *data)
{
  //dump	*local_data = static_cast<dump*>(data);

  if (keycode == ESCAPE)
    exit(0);
  else if (keycode == RIGHT)
    move_snake(1, static_cast<dump*>(data));
  else if (keycode == LEFT)
    move_snake(0, static_cast<dump*>(data));
  return (0);
}

int	MlxGfxParams::expose_redraw(void *data)
{
  dump	*local_data = static_cast<dump*>(data);
  mlx_put_image_to_window(local_data->mlx_ptr, local_data->win_ptr, local_data->img_ptr, 0, 0);
  return (0);
}

int	MlxGfxParams::gameLoop()
{
  printf("SNEKHEAD : x = %d, y = %d\n", data.snake->leFood.first, data.snake->leFood.second);
  updateImg(&(this->data));
  mlx_put_image_to_window(this->data.mlx_ptr, this->data.win_ptr, this->data.img_ptr, 0, 0);
  mlx_key_hook(this->data.win_ptr, key_event, static_cast<void *>(&(this->data)));
  mlx_expose_hook(this->data.win_ptr, expose_redraw, &(this->data));
  mlx_loop(this->data.mlx_ptr);
}

int	MlxGfxParams::my_pixel_put_to_image(int x, int y, dump *data, int color)
{
  int	pix;

  pix = ((x * (data->bpp / 8)) + (data->sizeline * y));
  data->img[pix] = color;
  data->img[pix + 1] = color >> 8;
  data->img[pix + 2] = color >> 16;
  return (0);
}
