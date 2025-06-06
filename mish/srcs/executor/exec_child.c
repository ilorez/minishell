/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:31:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 10:14:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include <signal.h>

void	handel_quit(int sig)
{
	(void)sig;
	printf("Quit (core dumped)\n");
}

void	ft_exec_child(t_data *data, t_ast *ast)
{
	char	*path;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (data->pipein != -1)
		close(data->pipein);
	ft_change_fd(data->fd[0], STDIN_FILENO, data);
	ft_change_fd(data->fd[1], STDOUT_FILENO, data);
	path = ft_get_right_path(data, ast->argv[0]);
	if (!path)
		ft_handel_exit(data, 127);
	execve(path, ast->argv, (char **)((g_mish.envp)->content));
	perror(path);
	free(path);
	ft_handel_exit(data, 126);
}
