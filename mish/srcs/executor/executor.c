/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:03:54 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/08 10:40:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <stdio.h>
#include <unistd.h>

// TODO:
//  - create a list called ind **wpids; that should waited everytime before run ast->right in all of OR|AND
int ft_executor(t_data *data, t_ast *ast)
{
  int status;
  
  if (!ast || ast->type == T_EOL)
    return (0);
  if (ast->type == T_OR)
  {
    status = ft_executor(data, ast->left);
    if (status != 0)
      status = ft_executor(data, ast->right);
  }
  else if (ast->type == T_AND)
  {
    status = ft_executor(data, ast->left);
    if (status == 0)
      status = ft_executor(data, ast->right);
  }
  else if (ast->type == T_PIPE)
  {
    // original_in = data->in;
    // original_out = data->out;
    
    // dup pipe after open it in data->in/out

    //ft_pipe();
    // close read pipe
    status = ft_executor(data, ast->left);
    // close write pipe 
    status = ft_executor(data, ast->right);
    // restore original in and out
  }
  else if (ast->type == T_SUBSH)
    status = ft_executor(data, ast->left);
  else if (ast->type == T_REDIR)
  {
    // TODO: redirect 
    // ft_redirect((t_redir *)ast->value);
    status = ft_executor(data, ast->left);
  }
  else if (ast->type == T_EXEC)
  {
    // TODO: execute
  }
  return (status);
}



int ft_pipe(t_data *data, t_ast *ast)
{
  int org[2];
  int pfd[2];
  int status;

  org[0] = data->fd[0];
  org[1] = data->fd[1];
  if (pipe(pfd) < 0)
  {
    perror("pipe");
    // free memory and stop cmd execution
  }

  data->fd[1] = pfd[1];
  status = ft_executor(data, ast->left);
  close(pfd[1]);
  data->fd[1] = org[1];
  data->fd[0] = pfd[0];
  status = ft_executor(data, ast->left);
  close(pfd[0]);
  data->fd[0] = org[0];
  return status;
}

int ft_exec(t_data *data, t_ast *ast)
{
  int pid;
  char **argv;
  char *path;

  argv = (char **)ast->value;
  if (argv || argv[0])
  {
    // make sure this error not happen
  }
  pid = fork();

  if (pid == -1)
  {
    perror("fork");
    // free memory and stop cmd
  }
  if (pid == 0)
  {
    path = ft_get_right_path(argv[0], data->paths);
    ft_change_fd(data->fd[0], STDIN_FILENO, data);
    ft_change_fd(data->fd[1], STDOUT_FILENO, data);
    // execute program
    execve(path, argv, data->envp);
    perror("execve");
    exit(126);
  }
  return 
}
