/*
** main.c for main in /home/gassem_a/Programmation_Elementaire/CPE_2015_BSQ
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sun Dec 20 16:49:43 2015 aurelien gassemann
** Last update Sun Dec 20 17:38:19 2015 aurelien gassemann
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int		main(int argc, char **argv)
{
  struct stat	*buf;
  int		fd;
  t_map		map;
  t_size	size;

  if (argc >= 2)
    {
      fd = open(argv[1], O_RDONLY);
      buf = malloc(sizeof(*buf));
      stat(argv[1], buf);
      map.buffer = malloc(buf->st_size);
      fill_empty_buffer(map, fd, buf->st_size);
      size.lines = count_lines(map);
      size.columns = count_columns(map);
      malloc_tab(map, size);
    }
  else
    {
      my_putstr("ERROR : YOU HAVE TO SPECIFIE A MAP AS ARGUMENT\n");
      return (0);
    }
  free (buf);
  free (map.buffer);
}
