/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:33:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/06/01 12:24:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"
#include "types.h"
#include "utils.h"

typedef struct s_coll {
  t_arr *list;
  int fd;
	void	(*clean)(t_ast *);
} t_coll;

// o for append to ast
// 1 for set fd
// 2 for free ast and close cmd
void ft_coll(t_ast *ast, int fd, int cmd)
{
  static t_coll cl;

  if (cmd == -1)
  {
    cl.list = arr_new();
    cl.fd = -1;
    cl.clean = ft_free_ast;
  }
  else if (cmd == 0)
  {
    arr_append(cl.list, ast);
  }
  else if (cmd == 1)
    cl.fd = fd;
  else
  {
    arr_clean(&cl.list);
    if (cl.fd >= 0)
      close(cl.fd);
    cl.fd = -1;
  }
}

