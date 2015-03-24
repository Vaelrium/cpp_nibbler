//
// leSnake.cpp for leSnake in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Tue Mar 24 13:56:25 2015 Rémi DURAND
// Last update Tue Mar 24 15:19:06 2015 Rémi DURAND
//

#include "./include/leSnake.hpp"
#include <cstdlib>

leSnake::leSnake(int width, int height)
{
  this->size = 4;
  this->hx = width / 2;
  this->hy = height / 2;
  this->dir = 0;
  this->dead = false;
  this->body.push_back(std::make_pair((width / 2) - 1, height / 2));
  this->body.push_back(std::make_pair((width / 2) - 2, height / 2));
  this->body.push_back(std::make_pair((width / 2) - 3, height / 2));
  this->newFood(width, height);
}

leSnake::leSnake(const leSnake& other)
{
  this->size = other.getSize();
  this->hx = other.getHx();
  this->hy = other.getHy();
  this->dir = other.getDir();
  this->dead = other.getDead();
  this->body = other.body;
}

leSnake::~leSnake()
{
}

leSnake&     leSnake::operator=(const leSnake &other)
{
  if (this != &other)
    {
      this->size = other.getSize();
      this->hx = other.getHx();
      this->hy = other.getHy();
      this->dir = other.getDir();
      this->dead = other.getDead();
      this->body = other.body;
    }
  return (*this);
}

int		leSnake::getSize() const
{
  return (this->size);
}

int		leSnake::getHx() const
{
  return (this->hx);
}

int		leSnake::getHy() const
{
  return (this->hy);
}

int		leSnake::getDir() const
{
  return (this->dir);
}

bool		leSnake::getDead() const
{
  return (this->dead);
}

void		leSnake::setSize(int par)
{
  this->size = par;
}

void		leSnake::setHx(int par)
{
  this->hx = par;
}

void		leSnake::setHy(int par)
{
  this->hy = par;
}

void		leSnake::setDir(int par)
{
  this->dir = par;
}

void		leSnake::setDead(bool par)
{
  this->dead = par;
}

void		leSnake::newFood(int width, int height)
{
  this->leFood = std::make_pair((rand() / width), (rand() / height));
}

void		leSnake::move()
{
  this->body.insert(this->body.begin(), std::make_pair(this->hx, this->hy));
  this->body.pop_back();
  if (this->dir == 0)
    this->hx++;
  else if (this->dir == 1)
    this->hy++;
  else if (this->dir == 2)
    this->hx--;
  else
    this->hy--;
}
