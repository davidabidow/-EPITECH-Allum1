/*
** checkwinsize.c for checkwinsize in /home/tran_0/rendu/Allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon Feb 10 11:17:09 2014 david tran
** Last update Tue Feb 11 13:39:20 2014 david tran
*/

#include "list.h"

void			checkwinsize(t_struct *vals)
{
  ioctl(0, TIOCGWINSZ, &vals->argp);
  if (vals->may > (vals->argp.ws_row - 2) ||
      (vals->may * 2 + 1) > vals->argp.ws_col)
    {
      my_putstr("IMPOSSIBLE with the window's size\n");
      exit(1);
    }
}

void			affturn(t_struct vals)
{
  tputs(tgoto(vals.tget->movecurs, 0, vals.argp.ws_row), 1, my_putchar);
  my_putstr("TURN : ");
  my_put_nbr(vals.turn);
}
