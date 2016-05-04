/*
** bsq.c for bsq in /home/gassem_a/Programmation_Elementaire/CPE_2015_BSQ_bootstrap
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Mon Nov 30 14:31:52 2015 aurelien gassemann
** Last update Sun Dec 20 16:52:26 2015 aurelien gassemann
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int	fill_empty_buffer(t_map map, int fd, int size_buf)
{
  int	idx;

  idx = 1;
  while (idx != 0)
    {
      idx = read(fd, map.buffer, size_buf);
    }
}

int	count_lines(t_map map)
{
  int	idx;
  int	j;

  idx = 0;
  j = 0;
  while (map.buffer[idx] != 0)
    {
      if (map.buffer[idx] == '\n')
	j = j + 1;
      idx = idx + 1;
    }
  return (j - 1);
}

int	count_columns(t_map map)
{
  int	idx;
  int	j;

  idx = 0;
  j = 0;
  while (map.buffer[idx] != '\n')
    idx = idx + 1;
  idx = idx + 1;
  while (map.buffer[idx] != '\n')
    {
      j = j + 1;
      idx = idx + 1;
    }
  return (j);
}

int	malloc_tab(t_map map, t_size size)
{
  int	idx;

  idx = 0;
  map.array = malloc(sizeof(int *) * size.lines);
  while (idx < size.lines)
    {
      map.array[idx++] = malloc(sizeof(int *) * size.columns);
    }
  fill_tab(map, size);
  free(map.array);
}

int		fill_tab(t_map map, t_size size)
{
  t_init	init;

  init.i = 0;
  init.j = 0;
  size.max = 0;
  while (map.buffer[init.i - 1] != '\n')
    init.i = init.i + 1;
  while (init.j != size.lines)
    {
      init.k = 0;
      while (init.k != size.columns)
	{
	  map.array[init.j][init.k] = check_characters(map, size, init);
	  if (map.array[init.j][init.k] > size.max)
	    size.max = map.array[init.j][init.k];
	  init.k = init.k + 1;
	  init.i = init.i + 1;
	}
      init.i = init.i + 1;
      init.j = init.j + 1;
    }
  size.x = 0;
  size.y = 0;
  detect_biggest_square(map, size, init);
}
