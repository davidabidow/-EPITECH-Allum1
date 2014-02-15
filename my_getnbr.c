/*
** my_getnbr.c for my_getnbr in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun Feb  2 12:26:47 2014 david tran
** Last update Sun Feb  2 12:48:33 2014 david tran
*/

int	my_getnbr(char *str)
{
  int	cnt_neg;
  int	i;
  int	nb;

  cnt_neg = 1;
  i = 0;
  nb = 0;
  while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
        cnt_neg = cnt_neg * -1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10;
      nb = nb + (str[i] - '0');
      if (nb < 0)
        if (nb != -2147483648 || cnt_neg == 1)
          return (0);
      i++;
    }
  return (nb * cnt_neg);
}
