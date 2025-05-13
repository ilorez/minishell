/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:16:07 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/10 14:05:29 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_free_tokens(t_token **tks)
{
	t_token	*tmp;

	if (!(*tks))
		return ;
	while ((*tks))
	{
		tmp = (*tks)->next;
		if ((*tks)->type == T_WORD && (*tks)->word)
			free((*tks)->word);
		free((*tks));
		(*tks) = tmp;
	}
}

void	exit_err(char *msg, t_errno code)
{
	ft_perror(msg, code);
	exit(code);
}

int restore_std(int std, int flags, int status)
{
  int fd;

  if (isatty(std))
  {
    close(std);
    fd = open("/dev/tty", flags);
    if (fd == -1)
    {
        perror("open /dev/tty");
        return (1);
    }
    else if (fd != std)
        return (ft_change_fd(fd, std, NULL));
  }
  return (status);
}

int handel_cmd_end(t_data *data)
{
  int status;

  status = 0;
  if (!data)
    return 0;
  if (data->wpids->index)
    status = ft_killpids(data->wpids);
  if (data->ast)
    ;//ft_free_ast(data->ast);
  status = restore_std(STDIN_FILENO, O_RDONLY, status);
  if (data->fd[0] != STDIN_FILENO)
    close(data->fd[0]);
  status = restore_std(STDOUT_FILENO, O_WRONLY, status);
  if (data->fd[1] != STDOUT_FILENO)
    close(data->fd[1]);
  return (status);
}

void ft_handel_exit(t_data *data, int status)
{
  if (!data)
    exit(status);
  handel_cmd_end(data);
  if (data->envp)
    ft_free_str_lst(data->envp);
  if (data->paths)
    ft_free_str_lst(data->paths);
  if (data->curr_dir)
    free(data->curr_dir);
  if (data->wpids)
    arr_free(data->wpids);
  exit(status);
}
