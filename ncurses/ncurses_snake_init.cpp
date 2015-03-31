//
// ncurses_snake_init.cpp for ncurses in /home/durand_u/github/cpp_nibbler/ncurses
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 30 14:40:58 2015 Rémi DURAND
// Last update Mon Mar 30 14:57:43 2015 Rémi DURAND
//

#include "./../IGfxParams.cpp"
#include "NcurGfxParams.hpp"
#include <ncurses/curses.h>

extern "C"
{
  IGfxParams    *init_lib(int win_x, int win_y, leSnake *snek)
  {
    return (new NcurGfxParams(win_x, win_y, snek));
  }
}
