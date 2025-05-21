/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:02:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 08:40:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

char	*ft_get_right_path(char *cmd)
{
	char *(path), *(paths), *(start);
	paths = ft_getenv("PATH");
	if (ft_strchr(cmd, '/') || !paths)
		return (ft_strdup(cmd));
	start = paths;
	while (*start)
	{
		if (*paths && *paths != ':' && ++paths)
			continue ;
		if (!*paths)
			path = ft_strjoin(start, cmd, "/");
		else
		{
			*paths = '\0';
			path = ft_strjoin(start, cmd, "/");
			*paths++ = ':';
		}
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		start = paths;
	}
	ft_perror(cmd, ERR_CMDNF);
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
