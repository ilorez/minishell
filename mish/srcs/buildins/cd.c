/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:28:22 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 00:10:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

// cd with only a relative or absolute path
//    cd [directory]
//
//  Change the current working directory to directory.
//  If directory is not supplied (just cd with no args),
//  the value of the HOME shell variable is used.
//  If ‘..’ appears in directory,
//  it is processed by removing the
//  immediately preceding pathname component,
//  back to a slash or the beginning of directory.
//
//  If the directory change is successful,
//  cd sets the value of the PWD environment
//        variable to the new directory name,
//  and sets the OLDPWD environment variable to
//  the value of the current working directory before the change.
//
//  The return status is zero if the directory
//  is successfully changed,
//  non-zero otherwise.

int	ft_cd(char **argv)
{
	char	*path;

	if (!argv || !*argv)
		path = getenv("HOME");
	else if (argv[0] && argv[1])
		return (ft_perror("cd", ERR_TO_MANY_ARG), 1);
	else
		path = argv[0];
	if (chdir(path) != 0)
	{
		ft_ref_perror("cd", path, ERR_ENOENT);
		return (1);
	}
	if (!getcwd(g_mish.cwd, PATH_MAX))
	{
		perror("cd");
		return (1);
	}
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	ft_setenv("PWD", g_mish.cwd, 1);
	return (0);
}
