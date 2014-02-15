/*
** my_put_nbr.c for my_put_nbr in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue Feb  4 13:48:18 2014 david tran
** Last update Tue Feb  4 13:53:10 2014 david tran
*/

#include "list.h"

void	my_put_nbr(int nb)
{
  int	a;
  int	c;

  a = 0;
  c = 1000000000;
  if (nb == 0)
    {
      my_putchar('0');
      return ;
    }
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putstr("-");
    }
  c = c / 10;
  boucle(nb, a, c);
}

int	boucle(int nb, int a, int c)
{
  while (a == 0)
    {
      a = nb / c;
      if (a == 0)
        {
          c = c / 10;
        }
    }
  my_putchar(48 + a);
  while (c >= 10)
    {
      a = nb % c;
      c = c / 10;
      a = a / c;
      my_putchar(48 + a);
    }
  return (0);
}
