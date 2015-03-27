//
// IGfxParams.cpp for  in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Thu Mar 26 13:05:49 2015 Ambroise Coutarel
// Last update Fri Mar 27 11:24:37 2015 Ambroise Coutarel
//

#include "./include/IGfxParams.hpp"
 extern "C"
 {
   IGfxParams::IGfxParams(int win_x, int win_y, leSnake *snek)
   {
     data.win_x = win_x;
     data.win_y = win_y;
     data.snake = snek;
   }
}
