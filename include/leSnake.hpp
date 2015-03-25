//
// leSnake.hpp for header in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Tue Mar 24 13:56:44 2015 Rémi DURAND
// Last update Wed Mar 25 11:26:49 2015 Rémi DURAND
//

#ifndef _LES_H_
# define _LES_H_

#include <utility>
#include <vector>

class		leSnake
{
private:
  int		size;
  int		hx;
  int		hy;
  int		dir;
  bool		dead;
public:
  std::pair<int, int>			leFood;
  std::vector<std::pair<int, int> >	body;
  leSnake(int, int);
  leSnake(const leSnake&);
  ~leSnake();
  leSnake&	operator=(const leSnake&);
  int		getSize() const;
  int		getHx() const;
  int		getHy() const;
  int		getDir() const;
  bool		getDead() const;
  void		setSize(int);
  void		setHx(int);
  void		setHy(int);
  void		setDir(int);
  void		setDead(bool);

  void		newFood(int, int);
  void		move(int, int);
  void		foodCheck(int, int);
};

#endif
