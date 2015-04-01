//
// SdlGfxParams.cpp for  in /home/ganesha/projets/cpp_nibbler/sdl
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 30 14:54:11 2015 Ambroise Coutarel
// Last update Wed Apr  1 14:40:21 2015 Ambroise Coutarel
//

#include "SfmlGfxParams.hpp"
#include "../include/nibbler.hpp"
#include <unistd.h>

SfmlGfxParams::SfmlGfxParams(int win_x, int win_y, leSnake *snek) : IGfxParams(win_x, win_y, snek)
{
}

SfmlGfxParams::~SfmlGfxParams()
{
}

int	SfmlGfxParams::move_snake(char dir, sf::RenderWindow *window)
{
  if (dir == 1)
    {
      data.snake->setDir(RIGHT_DEC(data.snake->getDir()));
    }
  else if (dir == 2)
    {
      data.snake->setDir(LEFT_INC(data.snake->getDir()));
    }
  drawSnake(window);
  return (0);
}

int		SfmlGfxParams::SfmlKeyEvents(sf::Event event, sf::RenderWindow *window)
{
  if (event.key.code == sf::Keyboard::Escape)
    {
      window->close();
      exit(0);
    }
  else if (event.key.code == sf::Keyboard::Left)
    move_snake(1, window);
  else if (event.key.code == sf::Keyboard::Right)
    move_snake(2, window);
  return (0);
}

int		SfmlGfxParams::sfmlWait(sf::RenderWindow *window)
{
  sf::Event	event;

  while (!data.snake->getDead())
    {
      data.snake->move();
      data.snake->deadCheck(data.win_x / BLOCK_SIZE, data.win_y / BLOCK_SIZE);
      data.snake->foodCheck(data.win_x / BLOCK_SIZE, data.win_y / BLOCK_SIZE);
      drawSnake(window);
      while (window->pollEvent(event))
	{
	  //std::cout << "event detected" << std::endl;
	  if (event.type == sf::Event::Closed)
	    {
	      window->close();
	      return (0);
	    }
	  else if (event.type == sf::Event::KeyPressed)
	    SfmlKeyEvents(event, window);
	}
      usleep(100000);
    }
  return (0);
}

int			SfmlGfxParams::drawSnake(sf::RenderWindow *window)
{
  sf::RectangleShape	square(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
  sf::Color		ground(0xFF, 0xFF, 0x87);
  sf::Color		food(0x27, 0xF5, 0xCF);
  sf::Color		sneakBody(0xDD, 0x27, 0xF5);
  sf::Color		sneakHead(0x03, 0xFF, 0x27);

  window->clear(ground);
  square.setPosition(data.snake->leFood.first * BLOCK_SIZE,
		     data.snake->leFood.second * BLOCK_SIZE);
  square.setFillColor(food);
  window->draw(square);
  square.setPosition(data.snake->getHx() * BLOCK_SIZE,
		     data.snake->getHy() * BLOCK_SIZE);
  square.setFillColor(sneakHead);
  window->draw(square);
  for(bodyVector::const_iterator it = data.snake->body.begin(); it != data.snake->body.end(); ++it)
    {
      square.setPosition(it->first * BLOCK_SIZE,
			 it->second * BLOCK_SIZE);
      square.setFillColor(sneakBody);
      window->draw(square);
    }
  window->display();
  return (0);
}

int		SfmlGfxParams::gameLoop()
{
  sf::RenderWindow window(sf::VideoMode(data.win_x, data.win_y), "KoujouSnake", sf::Style::Default);
  while (window.isOpen())
    {
      drawSnake(&window);
      sfmlWait(&window);
      window.close();
    }
  return (0);
}

extern "C"
{
  IGfxParams	*init_lib(int win_x, int win_y, leSnake *snek)
  {
    return (new SfmlGfxParams(win_x, win_y, snek));
  }
}
