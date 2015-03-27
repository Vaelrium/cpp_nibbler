//
// MlxGfxParams.cpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:40:15 2015 Ambroise Coutarel
// Last update Fri Mar 27 12:39:53 2015 Ambroise Coutarel
//

extern "C"
{
#include "mlx.h"
}
#include "../include/nibbler.hpp"
#include "MlxGfxParams.hpp"
#include <cstdlib>


extern "C"
{
  void	*mlx_init();
}

MlxGfxParams::MlxGfxParams(int win_x, int win_y, leSnake *snek) : IGfxParams(win_x, win_y, snek)
{
  //this->data.win_x = win_x;
  //this->data.win_y = win_y;
  this->data.mlx_ptr = mlx_init();
  this->data.win_ptr = mlx_new_window(this->data.mlx_ptr, win_x, win_y, "koujouSnake");
  this->data.img_ptr = mlx_new_image(this->data.mlx_ptr, win_x, win_y);
  this->data.img = mlx_get_data_addr(this->data.img_ptr, &(this->data.bpp),
				&(this->data.sizeline), &(this->data.endian));
  //this->data.snake = snek;
}

MlxGfxParams::~MlxGfxParams()
{
}

int	MlxGfxParams::drawSquare(int sq_x, int sq_y, dump *data)
{
  int x = 0, y = 0;

  while (y != BLOCK_SIZE)
    {
      while (x != BLOCK_SIZE)
  	{
	  my_pixel_put_to_image((sq_x + x), (sq_y + y), data, GROUND);
  	  ++x;
  	}
      ++y;
      x = 0;
    }
  return (0);
}

int	MlxGfxParams::drawSnake(dump *data)
{
  return 0;
}

int	MlxGfxParams::updateImg(dump *data)
{
  int	x = 0, y = 0, x_game = data->win_x / BLOCK_SIZE, y_game = data->win_y / BLOCK_SIZE;

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
  data->img[pix + 1] = color >> 2;
  data->img[pix + 2] = color >> 4;
  return (0);
}
