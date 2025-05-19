/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:15:12 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/19 11:52:11 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"
#include <fcntl.h>
#include <unistd.h>

int ft_run_buildin(t_buildin b, char **argv, t_data *data)
{
  int status;

  status = 0;
  if (b == B_UNKNOWN)
    return (0);
  if (b == B_CD)
    status = ft_cd(argv);
  else if (b == B_ECHO)
    status = ft_echo(argv);
  else if (b == B_ENV)
    status = ft_env(argv);
  else if (b == B_EXIT)
    ft_exit(argv, data);
  else if (b == B_EXPORT)
    status = ft_export(argv);
  else if (b == B_PWD)
    status = ft_pwd(argv);
  else if (b == B_UNSET)
    status = ft_unset(argv);
  return (status);
}

t_buildin is_buildin(char *path)
{
  if (!path)
    return (B_UNKNOWN);
  if (ft_strncmp(path, "cd", 3))
    return (B_CD);
  else if (ft_strncmp(path, "echo", 5))
    return (B_ECHO);
  else if (ft_strncmp(path, "env", 4))
    return (B_ENV);
  else if (ft_strncmp(path, "exit", 5))
    return (B_EXIT);
  else if (ft_strncmp(path, "export", 7))
    return (B_EXPORT);
  else if (ft_strncmp(path, "pwd", 4))
    return (B_UNSET);
  else if (ft_strncmp(path, "unset", 6))
    return (B_UNSET);
  return (B_UNKNOWN);
}
