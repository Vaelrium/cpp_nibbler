//
// MlxGfxParams.cpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:40:15 2015 Ambroise Coutarel
// Last update Tue Mar 31 14:59:39 2015 Rémi DURAND
//

extern "C"
{
#include <ncurses/curses.h>
}
#include "../include/nibbler.hpp"
#include "NcurGfxParams.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <algorithm>

extern "C"
{
  void	*mlx_init();
}

NcurGfxParams::NcurGfxParams(int win_x, int win_y, leSnake *snek) : IGfxParams(win_x, win_y, snek)
{
}

NcurGfxParams::~NcurGfxParams()
{
}

static void	gameLoopInit()
{
  initscr();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_RED);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
  init_pair(3, COLOR_BLUE, COLOR_BLUE);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  cbreak();
  keypad(stdscr, TRUE);
  timeout(0);
  curs_set(0);
  noecho();
  refresh();
}

static void	drawSnake(WINDOW *win, int height, int width, leSnake *snake)
{
  std::vector<std::pair<int, int> >::iterator	it;

  box(win, ACS_VLINE, ACS_HLINE);
  wattron(win, A_BOLD);
  wattron(win, COLOR_PAIR(1));
  mvwprintw(win, snake->leFood.second, snake->leFood.first, "O");
  wattron(win, COLOR_PAIR(3));
  mvwprintw(win, snake->getHy(), snake->getHx(), " ");

  wattron(win, COLOR_PAIR(2));
  for (it = snake->body.begin(); it != snake->body.end(); it++)
      mvwprintw(win, it->second, it->first, " ");
  wattron(win, COLOR_PAIR(4));
  wrefresh(win);
}

int		NcurGfxParams::gameLoop()
{
  WINDOW	*win;
  int		ch;

  gameLoopInit();
  win = newwin(data.win_x / BLOCK_SIZE, data.win_y / BLOCK_SIZE, 0, 0);
  wrefresh(win);
  while (data.snake->getDead() != true)
    {
      data.snake->move();
      data.snake->deadCheck(data.win_x / BLOCK_SIZE, data.win_y / BLOCK_SIZE);
      data.snake->foodCheck(data.win_x / BLOCK_SIZE, data.win_y / BLOCK_SIZE);
      wclear(win);
      drawSnake(win, data.win_x, data.win_x, data.snake);
      ch = getch();
      if (ch == KEY_LEFT)
	data.snake->setDir(RIGHT_DEC(data.snake->getDir()));
      else if (ch == KEY_RIGHT)
	data.snake->setDir(LEFT_INC(data.snake->getDir()));
      else if (ch == 27)
	{
	  if ((ch = getch()) == ERR)
	    data.snake->setDead(true);
	}
      usleep(105000);
    }
  endwin();
  return (0);
}
