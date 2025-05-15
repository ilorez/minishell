/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:03:54 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 16:17:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

// TODO: test expand path name
//        - for current dir this ./main.c sould work as main.c so just skip ./
//        - more tests
//        - norm
void ft_exec(t_data *data, t_ast *ast);
int ft_pipe(t_data *data, t_ast *ast);
int ft_redir(t_data *data, t_ast *ast, t_redir *r);
static int _or_and(t_data *data, t_ast *ast, int cond);

int ft_executor(t_data *data, t_ast *ast)
{
  int status;
  
  status = 0;
  if (!ast || ast->type == T_EOL)
    return (0);
  if (ast->type == T_OR)
    status = _or_and(data, ast, 0);
  else if (ast->type == T_AND)
    status = _or_and(data, ast, 1);
  else if (ast->type == T_PIPE)
    ft_pipe(data, ast);
  else if (ast->type == T_SUBSH)
  {
    t_arr *tmp;
    tmp = data->wpids;
    data->wpids = arr_new();
    status = ft_executor(data, ast->left);
    data->wpids = arr_merge(tmp, data->wpids);
  }
  else if (ast->type == T_REDIR)
    status = ft_redir(data, ast, ast->redir);
  else if (ast->type == T_EXEC)
    ft_exec(data, ast);
  return (status);
}

static int _or_and(t_data *data, t_ast *ast, int cond)
{
  int status;

  status = ft_executor(data, ast->left);
  if (data->wpids->index)
    status = ft_waitpids(data->wpids);
  if ((status == 0) == cond)
    status = ft_executor(data, ast->right);
  return status;
}

int ft_pipe(t_data *data, t_ast *ast)
{
  int org[2];
  int pfd[2];
  int status;

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
  return status;
}

void ft_exec(t_data *data, t_ast *ast)
{
  int *pid;
  char **argv;
  char *path;

  pid = ft_calloc(sizeof(int), 1);
  *pid = fork();

  if (*pid == -1)
  {
    perror("fork");
    ft_handel_exit(data, 2);
  }
  else if (*pid == 0)
  {
    // TODO: replace ./ with data->curr_path
    argv = ft_extract(ast->argv);
    path = ft_get_right_path(argv[0], data->paths);
    if (!argv)
      return (ft_perror(NULL, ERR_MALLOC_FAIL), exit(3));
    ft_change_fd(data->fd[0], STDIN_FILENO, data);
    ft_change_fd(data->fd[1], STDOUT_FILENO, data);
    // execute program
    execve(path, argv, data->envp);
    perror("execve");
    // TODO: free
    exit(126);
  }
  arr_append(data->wpids, pid);
}

int ft_redir(t_data *data, t_ast *ast, t_redir *r)
{
  int fd;
  t_arr *wild_paths;

  wild_paths = ft_word_expansion(r->fpath);
  if (!wild_paths)
      return (ft_perror(NULL, ERR_MALLOC_FAIL) , 1);
  if (wild_paths->index > 1)
    return (arr_free(wild_paths), ft_perror(r->fpath, ERR_AMB_REDIR), 1);
  free(r->fpath);
  r->fpath = wild_paths->content[0];
  free(wild_paths->content);
  free(wild_paths);
  fd = open(r->fpath, r->flags, r->mode);
  if (fd < 0)
  {
    perror("open");
    return (1);
  }
  ft_change_fd(fd, r->fd, data);
  return (ft_executor(data, ast->left));
}
