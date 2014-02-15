/*
** list.h for list in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Jan 31 10:43:16 2014 david tran
** Last update Sat Feb 15 21:52:03 2014 david tran
*/

#ifndef _LIST_H_
# define _LIST_H_

#include <sys/ioctl.h>
#include <curses.h>
#include <term.h>
#include <ncurses/curses.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_tget
{
  char			*hidecurs;
  char			*clears;
  char			*movecurs;
  char			*underline;
  char			*endunder;
  char			*revvid;
  char			*endrev;
  char			*endhide;
}			t_tget;

typedef struct		s_struct
{
  int			max;
  int			may;
  int			midd;
  int			x;
  int			y;
  int			pars;
  int			turn;
  struct winsize	argp;
  t_tget		*tget;
}			t_struct;

typedef struct		s_booly
{
  int			status;
  int			bolly;
}			t_booly;

char			*my_strcpy(char *, char *);
char			*my_strdup(char *);
int			my_strlen(char *);
int			dogent(int );
void			my_putstr(char *);
int			my_putchar(int );
int			calclines(t_struct *);
int			my_getnbr(char *);
void			gonormal(t_struct *);
int			checkargs(char **);
void			gorange(t_struct *, char **);
void			gonumb(t_struct *, char **);
void			my_put_nbr(int );
int			boucle(int ,int , int );
void			afffile(t_struct , t_booly *);
void			makeread(t_struct , t_booly *);
void			goright(t_struct , t_booly *, int *);
void			goleft(t_struct , t_booly *, int *);
void			pressenter(t_struct *, t_booly *);
void			pressspace(t_struct , t_booly *, int *);
void			calccoord(int *, int *, t_struct , int *);
void			pressup(t_struct , t_booly *, int *);
void			pressdown(t_struct , t_booly *, int *);
int			checkok(t_struct , t_booly *, int *);
int			checkfinal(t_struct , t_booly *);
void			iffinaldo(t_struct , t_booly *);
void			get_back(struct termios *);
void			endfeed(t_struct , int *, int *, t_booly *);
void			middfeed(t_struct , int *, int *, t_booly *);
void			finalizeia(t_struct *, t_booly *, int );
void			execia(t_struct *, t_booly *, int );
void			initia(t_struct *, t_booly *);
void			checkia(t_struct *, t_booly *);
void			iffinalia(t_struct *, t_booly *);
t_booly			*fillin(t_struct );
void			refreshall(t_struct *, t_booly *, int *);
void			fillstruct(t_struct *);
void			checkwinsize(t_struct *);
void			affturn(t_struct );
void			prefinalize(t_struct *, t_booly *, int , int );

#endif /* !_LIST_H_ */
