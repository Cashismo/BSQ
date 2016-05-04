/*
** fonctions.c for fonctions in /home/gassem_a/Programmation_Elementaire/CPE_2015_BSQ
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sun Dec 20 16:41:40 2015 aurelien gassemann
** Last update Sun Dec 20 16:54:02 2015 aurelien gassemann
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
