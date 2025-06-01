/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:02:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/06/01 19:57:34 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "utils.h"
#include <sys/stat.h>
#include <sys/wait.h>

void	_check_is_file(t_data *data, char *path)
{
	struct stat	src;

	if (stat(path, &src) != 0)
		return (perror("stat"), ft_handel_exit(data, 127));
	if (S_ISDIR(src.st_mode))
		return (ft_perror(path, ERR_ISDIR), ft_handel_exit(data, 126));
}

char	*ft_get_right_path(t_data *data, char *cmd)
{
	char *(path), *(paths), *(start);
	paths = ft_getenv("PATH");
	if (!ft_strncmp(cmd, "..", 3) || !ft_strncmp(cmd, ".", 2))
		return (ft_perror(cmd, ERR_CMDNF), NULL);
	if (ft_strchr(cmd, '/') || !paths)
		return (_check_is_file(data, cmd), ft_strdup(cmd));
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
	return (ft_perror(cmd, ERR_CMDNF), NULL);
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
	int	is_normal_exit;

	i = -1;
	status = 0;
	is_normal_exit = 1;
	while (++i < pid->index)
	{
		if (*(int *)(pid->content[i]) <= 0)
		{
			g_mish.exit_status = *(int *)(pid->content[i]) * -1;
			continue ;
		}
		waitpid(*(int *)(pid->content[i]), &status, 0);
		is_normal_exit = ft_check_status(status);
	}
	arr_empty(pid);
	if (!is_normal_exit && WIFSIGNALED(status))
		if (ft_wcoredump(status))
			printf("Quit (core dumped)\n");
	return (is_normal_exit);
}
