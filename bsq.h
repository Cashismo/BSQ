/*
** bsq.h for bsq.h in /home/gassem_a/Programmation_Elementaire/CPE_2015_BSQ_bootstrap
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Fri Dec 18 17:44:51 2015 aurelien gassemann
** Last update Sat Dec 19 17:03:57 2015 aurelien gassemann
*/

#ifndef MY_BSQ_H
# define MY_BSQ_H_

typedef struct	s_init
{
  int	i;
  int	j;
  int	k;
  int	temporary1;
  int	temporary2;
}		t_init;

typedef struct	s_map
{
  int	**array;
  char	*buffer;
}		t_map;

typedef struct	s_size
{
  int	max;
  int	lines;
  int	columns;
  int	x;
  int	y;
}		t_size;

#endif /* !MY_BSQ_H_ */
