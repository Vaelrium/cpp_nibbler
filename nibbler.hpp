//
// nibbler.hpp for header in /home/durand_u/github/cpp_nibbler
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Mon Mar 23 10:41:04 2015 Rémi DURAND
// Last update Tue Mar 24 15:26:14 2015 Rémi DURAND
//

#ifndef _NIB_H_
# define _NIB_H_

#include <cstdlib>
#include <iostream>
#include <string>
#include <dlfcn.h>

#define BLOCK_SIZE 10

int		init_nib(const int width, const int height, std::string lib, void **handler);
int		algo_snake(const int width, const int height, void *handler);

#endif /* !_NIB_H_ */
