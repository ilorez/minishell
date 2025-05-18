/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buildins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:15:12 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/18 23:41:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

// TODO:
//    - ofcourse it's not like that
//    - we should know that buildins run in parent process
//    - also think about read and write what should do of it
//    - create another function that check if that buildin after that run another function that run this buildin
//   j 
int ft_check_buildins(char *path, char **argv, t_data *data)
{
  int status;

  if (!path)
    return (1);
  if (ft_strncmp(path, "cd", 3))
    status = ft_cd(argv);
  else if (ft_strncmp(path, "echo", 5))
    status = ft_echo(argv);
  else if (ft_strncmp(path, "env", 4))
    status = ft_env(argv);
  else if (ft_strncmp(path, "exit", 5))
    ft_exit(argv, data);
  else if (ft_strncmp(path, "export", 7))
    status = ft_export(argv);
  else if (ft_strncmp(path, "pwd", 4))
    status = ft_pwd(argv);
  else if (ft_strncmp(path, "unset", 6))
    status = ft_unset(argv);
  else 
    return (1);
  return (status);
}
