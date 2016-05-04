/*
** square.c for square in /home/gassem_a/Programmation_Elementaire/CPE_2015_BSQ
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sun Dec 20 16:45:43 2015 aurelien gassemann
** Last update Sun Dec 20 16:55:42 2015 aurelien gassemann
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int	find_square(t_size size, t_map map, t_init init)
{
  int	a;
  int	b;
  int	c;

  size.max = 0;
  a = map.array[init.j - 1][init.k];
  b = map.array[init.j][init.k - 1];
  c = map.array[init.j - 1][init.k - 1];
  if (a < b)
    b = a;
  if (b < c)
    c = b;
  return (c + 1);
}

int	detect_biggest_square(t_map map, t_size size, t_init init)
{
  while (map.array[size.x][size.y] != size.max)
    {
      if (size.y < size.columns)
	size.y = size.y + 1;
      else
	{
	  size.y = 0;
	  size.x = size.x + 1;
	}
    }
  init.temporary1 = size.y - size.max;
  init.temporary2 = size.x - size.max;
  while (size.y != init.temporary1)
    {
      size.x = init.temporary2 + size.max;
      while (size.x != init.temporary2)
	{
	  map.array[size.x][size.y] = -1;
	  size.x = size.x - 1;
	}
      size.y = size.y - 1;
    }
  display(size, init, map);
}

int	check_characters(t_map map, t_size size, t_init init)
{
  if (map.buffer[init.i] == 'o')
    return (0);
  else if (init.k == 0 || init.j == 0)
    return (1);
  else if (map.buffer[init.i] == '.')
    return (find_square(size, map, init));
}

int	display(t_size size, t_map map)
{
  size.y = 0;
  while (size.y != size.lines)
    {
      size.x = 0;
      while (size.x != size.columns)
	{
	  if (map.array[size.y][size.x] == -1)
	    my_putchar('x');
	  else if (map.array[size.y][size.x] == 0)
	    my_putchar('o');
	  else
	    my_putchar('.');
	  size.x = size.x + 1;
	}
      my_putchar('\n');
      size.y = size.y + 1;
    }
}
