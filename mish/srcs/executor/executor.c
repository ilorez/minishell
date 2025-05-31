/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:03:54 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 18:57:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include <stdlib.h>

int			ft_exec(t_data *data, t_ast *ast);
int			ft_pipe(t_data *data, t_ast *ast);
static int	_or_and(t_data *data, t_ast *ast, int cond);

// the "()" is for priority nothing else
// tmp = data->wpids;
// data->wpids = arr_new();
// data->wpids = arr_merge(tmp, data->wpids);
int	ft_executor(t_data *data, t_ast *ast)
{
	int	status;

	status = 0;
	if (!ast || ast->type == T_EOL)
		return (g_mish.exit_status);
	if (ast->type == T_OR)
		status = _or_and(data, ast, 0);
	else if (ast->type == T_AND)
		status = _or_and(data, ast, 1);
	else if (ast->type == T_PIPE)
		ft_pipe(data, ast);
	else if (ast->type == T_SUBSH)
		status = ft_executor(data, ast->left);
	else if (ast->type == T_REDIR)
		status = ft_redir(data, ast, ast->redir);
	else if (ast->type == T_EXEC)
		status = ft_exec(data, ast);
	return (status);
}

// r: is
static int	_or_and(t_data *data, t_ast *ast, int cond)
{
	int	is_normal_exit;

	is_normal_exit = 1;
	g_mish.exit_status = ft_executor(data, ast->left);
	if (data->wpids->index)
		is_normal_exit = ft_waitpids(data->wpids);
	if (is_normal_exit && (g_mish.exit_status == 0) == cond)
		g_mish.exit_status = ft_executor(data, ast->right);
	return (g_mish.exit_status);
}

int	ft_pipe(t_data *data, t_ast *ast)
{
	int	org[2];
	int	pfd[2];
	int	status;

	status = 0;
	org[0] = data->fd[0];
	org[1] = data->fd[1];
	if (pipe(pfd) < 0)
	{
		perror("pipe");
		ft_handel_exit(data, status);
	}
	data->fd[1] = pfd[1];
	data->pipein = pfd[0];
	status = ft_executor(data, ast->left);
	close(pfd[1]);
	data->fd[0] = pfd[0];
	data->fd[1] = org[1];
	data->pipein = -1;
	status = ft_executor(data, ast->right);
	close(pfd[0]);
	data->fd[0] = org[0];
	return (status);
}

// TODO: replace ./ with data->curr_path
int	ft_exec(t_data *data, t_ast *ast)
{
	int			*pid;
	t_buildin	buildin;

	ast->argv = ft_extract(ast->argv);
	if (!ast->argv)
		return (ft_perror(NULL, ERR_MALLOC_FAIL), ft_handel_exit(data, 1), 1);
	if (!ast->argv[0][0])
		return (0);
	buildin = ft_is_buildin(ast->argv[0]);
	if (buildin)
		return (ft_run_buildin(buildin, &ast->argv[1], data));
	pid = ft_calloc(sizeof(int), 1);
	*pid = fork();
	if (*pid == -1)
		return (free(pid), perror("fork"), ft_free_data(&data), 1);
	else if (*pid == 0)
	{
		free(pid);
		ft_exec_child(data, ast);
	}
	arr_append(data->wpids, pid);
	return (0);
}
