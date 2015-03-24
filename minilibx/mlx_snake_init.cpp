//
// mlx_init.cpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:35:36 2015 Ambroise Coutarel
// Last update Tue Mar 24 13:05:41 2015 Ambroise Coutarel
//

#include "mlx.h"
#include "MlxGfxParams.hpp"

extern "C"
{
  IGfxParams	*init_lib(int win_x, int win_y)
  {
    //MlxGfxParams	*jeff= new MlxGfxParams(win_x, win_y);

    return (new MlxGfxParams(win_x, win_y));
  }
}
