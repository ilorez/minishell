/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:02:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/20 13:44:06 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

// get path can be founded
char	*ft_get_right_path(char *cmd, char **paths)
{
	char	*path;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path = NULL;
	while (*paths)
	{
		path = ft_strjoin(paths[0], cmd, "/");
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	ft_putstr_fd("Command '", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("' not found\n", STDERR_FILENO);
	return (NULL);
}

int	ft_dup2(int fd, int to, t_data *data)
{
  if (fd == to)
		return (true);
	if (dup2(fd, to) == -1)
	{
		perror("dup2");
		ft_handel_exit(data, 2);
	}
	return (true);
}

int	ft_change_fd(int fd, int to, t_data *data)
{
  if (fd == to)
		  return (true);
  ft_dup2(fd, to, data);
	close(fd);
	return (true);
}

int	ft_waitpids(t_arr *pid)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (++i < pid->index)
	{
		waitpid(*(int *)(pid->content[i]), &status, 0);
		if (ft_wifexited(status))
			status = ft_wexitstatus(status);
		else
			status = 0;
	}
	arr_empty(pid);
	return (status);
}

int	ft_killpids(t_arr *pid)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (++i < pid->index)
		kill(*(int *)(pid->content[i]), SIGTERM);
	arr_empty(pid);
	return (status);
}
