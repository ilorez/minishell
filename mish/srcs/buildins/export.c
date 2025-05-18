/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:39:33 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/18 21:56:00 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

// Mark each name to be passed to child processes in the environment.
// the names refer to shell variables not functions.
// If no names are supplied, a list of names of all exported variables is displayed.
// If a variable name is followed by =value, the value of the variable is set to value.
// The return status is zero unless an invalid option is supplied, 
// one of the names is not a valid shell variable name 

int ft_export(char **argv)
{
  int i;
  char *value;
  int status;

  if (!argv || !*argv) 
    return (ft_env(argv));
  i = -1;
  status = 0;
  while (argv[++i])
  {
    value = ft_strchr(argv[i], '=');
    if (value)
      *value = 0;
    if (!ft_isvalid_id(argv[i]))
    {
      if (value)
        *value = '=';
      ft_ref_perror("export", argv[i], ERR_IDENT);
      status = 1;
      continue;
    }
    ft_setenv(argv[i], value, 1);
  }
  return (status);
}

