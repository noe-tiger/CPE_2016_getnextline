/*
** gnl.h for  in /home/noe/gnl
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Fri Apr 14 13:32:38 2017 Noé
** Last update Fri Apr 14 13:35:52 2017 Noé
*/

#ifndef		GNL_H_
# define	GNL_H_

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct	s_char
{
  char		c;
  struct s_char	*next;
}		t_char;

#endif		/* !GNL_H_ */
