/*
** mlx_pixel_put_to_image.c for  in /home/ganesha/projets/cpp_nibbler/minilibx
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Thu Mar 26 12:04:45 2015 Ambroise Coutarel
// Last update Thu Mar 26 12:31:58 2015 Ambroise Coutarel
*/

#include "mlx.h"

extern "C"
{
int	my_pixel_put_to_image(int x, int y, dump *data, int color)
{
  int	pix;

  pix = ((x * (data->bpp / 8)) + (data->sizeline * y));
  data->img[pix] = color;
  data->img[pix + 1] = color >> 2;
  data->img[pix + 2] = color >> 4;
  return (0);
}
}
