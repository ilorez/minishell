/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:31:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 09:13:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

void	ft_exec_child(t_data *data, t_ast *ast)
{
	char	*path;

  signal(SIGQUIT, SIG_DFL);
	ft_change_fd(data->fd[0], STDIN_FILENO, data);
	ft_change_fd(data->fd[1], STDOUT_FILENO, data);
	path = ft_get_right_path(ast->argv[0]);
	if (!path)
		ft_handel_exit(data, 127);
	execve(path, ast->argv, (char **)((g_mish.envp)->content));
	perror(path);
	ft_handel_exit(data, 126);
}
