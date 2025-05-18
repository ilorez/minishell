/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:28:22 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/18 18:59:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/buildins.h"

//cd with only a relative or absolute path
//    cd [directory]
//
//    Change the current working directory to directory.
//    If directory is not supplied (just cd with no args), the value of the HOME shell variable is used. 
//    If ‘..’ appears in directory, it is processed by removing the immediately preceding pathname component,
//    back to a slash or the beginning of directory.
//
//    If the directory change is successful, cd sets the value of the PWD environment variable to the new directory name,
//    and sets the OLDPWD environment variable to the value of the current working directory before the change.
//
//    The return status is zero if the directory is successfully changed, non-zero otherwise.

int ft_cd(char **argv)
{
  char cwd[PATH_MAX];
  char *path;

  if (argv[0] && argv[1])
    return (ft_perror("cd", ERR_TO_MANY_ARG), 1);
  path = argv[0];
  if (!path)
    path = getenv("HOME");
  if (chdir(path) != 0)
  {
    ft_ref_perror("cd", path, ERR_ENOENT);
    return (1);
  }
  if (!getcwd(cwd, PATH_MAX))
  {
    perror("cd");
    return (1);
  }
  ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
  ft_setenv("PWD", cwd, 1);
  ft_memcpy(mish.cur_dir, cwd, ft_strlen(cwd));
  return (0);
}
