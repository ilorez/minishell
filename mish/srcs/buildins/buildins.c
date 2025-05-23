/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:15:12 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/23 12:09:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"
#include <fcntl.h>
#include <unistd.h>

static void	_save_org(t_data *data, int *org, int std, int index)
{
	if (std != data->fd[index])
	{
		*org = dup(std);
		ft_dup2(data->fd[index], std, data);
	}
	else
		*org = std;
}

static int _run_buildin(t_buildin b, char **argv, t_data *data)
{
  if (b == B_CD)
		return ft_cd(argv);
	if (b == B_ECHO)
		return (ft_echo(argv));
	if (b == B_ENV)
		return (ft_env(argv));
	if (b == B_EXIT)
		ft_exit(argv, data);
	if (b == B_EXPORT)
		return (ft_export(argv));
	if (b == B_PWD)
		return (ft_pwd(argv));
	if (b == B_UNSET)
		  return (ft_unset(argv));
  return (0);
}

int	ft_run_buildin(t_buildin b, char **argv, t_data *data)
{
	int		*status;
	t_iofd	org;

	status = ft_calloc(1, sizeof(int));
	if (b == B_UNKNOWN)
		return (0);
	_save_org(data, &(org.in), STDIN_FILENO, 0);
	_save_org(data, &(org.out), STDOUT_FILENO, 1);
  _run_buildin(b, argv, data);
	ft_change_fd(org.in, STDIN_FILENO, data);
	ft_change_fd(org.out, STDOUT_FILENO, data);
  *status *= -1;
  arr_append(data->wpids, status);
	return (*status * -1);
}

t_buildin	ft_is_buildin(char *path)
{
	if (!path)
		return (B_UNKNOWN);
	if (ft_strncmp(path, "cd", 3) == 0)
		return (B_CD);
	else if (ft_strncmp(path, "echo", 5) == 0)
		return (B_ECHO);
	else if (ft_strncmp(path, "env", 4) == 0)
		return (B_ENV);
	else if (ft_strncmp(path, "exit", 5) == 0)
		return (B_EXIT);
	else if (ft_strncmp(path, "export", 7) == 0)
		return (B_EXPORT);
	else if (ft_strncmp(path, "pwd", 4) == 0)
		return (B_PWD);
	else if (ft_strncmp(path, "unset", 6) == 0)
		return (B_UNSET);
	return (B_UNKNOWN);
}
