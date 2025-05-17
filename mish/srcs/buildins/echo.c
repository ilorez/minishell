/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:51:10 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/17 18:30:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

// echo with option -n
//
//    echo [-n] [arg …]
//
//    Output the args, separated by spaces, terminated with a newline.
//    The return status is 0 unless a write error occurs. If -n is specified,
//    the trailing newline is suppressed.
//
//    echo interprets the following escape sequences: 
//        -n:  new line 

int ft_echo(char **argv)
{
  int (i) ,(j);
  int is_newline;
  
  i = -1;
  is_newline = 1;
  while (argv[++i] && argv[i][0] == '-' && argv[i][1] == 'n')
  {
    j = 0;
    while (argv[i][++j] == 'n')
      ;
    if (!ft_isspace(argv[i][j]))
    {
      is_newline = 1;
      break;
    }
  }
  while (argv[i])
  {
    ft_putstr_fd(argv[i], 1);
    if (argv[++i])
      write(1, " ", 1);
  }
  if (is_newline)
      write(1, "\n", 1);
  return (0);
}
