/*
** makeread.c for makeread in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue Feb  4 21:42:20 2014 david tran
** Last update Sun Feb 16 05:18:39 2014 david tran
*/

#include "list.h"

void    raw_mode(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, t);
}

void    get_back(struct termios *t)
{
  t->c_lflag = ICANON;
  t->c_lflag = ECHO;
  tcsetattr(0, TCSANOW, t);
}

void			keyreads(int buffer, t_struct *vals, t_booly *booh,
				 int *j)
{
  struct termios	t;

  if (buffer == 4414235)
    goright(*vals, booh, j);
  else if (buffer == 4479771)
    goleft(*vals, booh, j);
  else if (buffer == 27)
    {
      tcgetattr(0, &t);
      tputs(vals->tget->endhide, 1, my_putchar);
      get_back(&t);
      free(booh);
      exit(1);
    }
  else if (buffer == 10)
    pressenter(vals, booh);
  else if (buffer == 32)
    pressspace(*vals, booh, j);
  else if (buffer == 4348699)
    pressup(*vals, booh, j);
  else if (buffer == 4283163)
    pressdown(*vals, booh, j);
  else if (buffer == 114)
    refreshall(vals, booh, j);
}

void			makeread(t_struct vals, t_booly *booh)
{
  int			readed;
  int			buffer;
  struct termios	t;
  int			j;
  
  tcgetattr(0, &t);
  raw_mode(&t);
  j = 0;
  buffer = 0;
  affturn(vals, booh);
  tputs(tgoto(vals.tget->movecurs, 0, 0), 1, my_putchar);
  while ((readed = read(0, &buffer, 4)) != 0)
    {
      keyreads(buffer, &vals, booh, &j);
      buffer = 0;
    }
}
