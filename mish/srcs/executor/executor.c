/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:03:54 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/19 16:17:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

int			ft_exec(t_data *data, t_ast *ast);
int			ft_pipe(t_data *data, t_ast *ast);
int			ft_redir(t_data *data, t_ast *ast, t_redir *r);
static int	_or_and(t_data *data, t_ast *ast, int cond);

// the "()" is for priority nothing else
//tmp = data->wpids;
//data->wpids = arr_new();
//data->wpids = arr_merge(tmp, data->wpids);
int	ft_executor(t_data *data, t_ast *ast)
{
	int		status;

	status = 0;
	if (!ast || ast->type == T_EOL)
		return (mish.exit_status);
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

static int	_or_and(t_data *data, t_ast *ast, int cond)
{
	int	status;

	status = ft_executor(data, ast->left);
	if (data->wpids->index)
		status = ft_waitpids(data->wpids);
	if ((status == 0) == cond)
		status = ft_executor(data, ast->right);
	return (status);
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
	status = ft_executor(data, ast->left);
	close(pfd[1]);
	data->fd[1] = org[1];
	data->fd[0] = pfd[0];
	status = ft_executor(data, ast->right);
	close(pfd[0]);
	data->fd[0] = org[0];
	return (status);
}

// TODO: replace ./ with data->curr_path
int	ft_exec(t_data *data, t_ast *ast)
{
	int		*pid;
	char	**argv;
	char	*path;
  t_buildin buildin;

  ft_change_fd(data->fd[0], STDIN_FILENO, data);
	ft_change_fd(data->fd[1], STDOUT_FILENO, data);
  argv = ft_extract(ast->argv);
	if (!argv)
		  return (ft_perror(NULL, ERR_MALLOC_FAIL), ft_handel_exit(data, 1), 1);
  buildin = ft_is_buildin(argv[0]);
  if (buildin)
    return (ft_run_buildin(buildin, &argv[1], data));
	pid = ft_calloc(sizeof(int), 1);
	*pid = fork();
	if (*pid == -1)
		return (perror("fork"), ft_free_data(data), 1);
	else if (*pid == 0)
	{
		path = ft_get_right_path(argv[0], data->paths);
		if (!path)
			ft_handel_exit(data, 1);
		execve(path, argv, (char **)(mish.envp->content));
		perror("execve");
		ft_handel_exit(data, 126);
	}
	arr_append(data->wpids, pid);
  return (0);
}

int	ft_redir(t_data *data, t_ast *ast, t_redir *r)
{
	int		fd;
	t_arr	*lst;
  int org;
  int status;

	lst = ft_extract_arg(r->fpath);
	if (!lst)
		return (ft_perror(NULL, ERR_MALLOC_FAIL), 1);
	if (lst->index > 1)
		return (ft_perror(r->fpath, ERR_AMB_REDIR), arr_free(lst), 1);
	free(r->fpath);
	r->fpath = lst->content[0];
	arr_free_body(lst);
	fd = open(r->fpath, r->flags, r->mode);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
  org = data->fd[r->fd];
  data->fd[r->fd] = fd;
  status = ft_executor(data, ast->left);
  data->fd[r->fd] = org;
	return (status);
}
