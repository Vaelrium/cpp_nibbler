//
// MlxGfxParams.cpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:40:15 2015 Ambroise Coutarel
// Last update Tue Mar 24 13:13:30 2015 Ambroise Coutarel
//

extern "C"
{
#include "mlx.h"
}
#include "MlxGfxParams.hpp"

MlxGfxParams::MlxGfxParams(int win_x, int win_y)
{
  this->win_x = win_x;
  this->win_y = win_y;
  this->mlx_ptr = mlx_init();
  this->win_ptr = mlx_new_window(this->mlx_ptr, win_x, win_y, "koujouSnake");
  this->img_ptr = mlx_new_image(this->mlx_ptr, win_x, win_y);
  this->img = mlx_get_data_addr(this->img_ptr, &(this->bpp),
				&(this->sizeline), &(this->endian));
}

MlxGfxParams::~MlxGfxParams()
{
}

int	MlxGfxParams::getWin_x() const
{
  return (win_x);
}

int	MlxGfxParams::getWin_y() const
{
  return (win_y);
}

int	MlxGfxParams::getBpp() const
{
  return (bpp);
}

int	MlxGfxParams::getSizeline() const
{
  return (sizeline);
}

int	MlxGfxParams::getEndian() const
{
  return (endian);
}
