/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:18:05 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 08:42:10 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_restore_std(int std, int flags, int status)
{
	int	fd;

	if (!isatty(std))
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

void	ft_free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	else if (ast->type == T_AND || ast->type == T_OR || ast->type == T_PIPE)
	{
		ft_free_ast(ast->left);
		ft_free_ast(ast->right);
	}
	else if (ast->type == T_SUBSH)
		ft_free_ast(ast->left);
	else if (ast->type == T_EXEC)
		ft_free_str_lst(ast->argv);
	else if (ast->type == T_REDIR)
	{
		free(ast->redir->fpath);
		free(ast->redir);
		ft_free_ast(ast->left);
	}
	free(ast);
}

int	handel_cmd_end(t_data *data)
{
	int	status;

	status = 0;
	if (!data)
		return (0);
	if (data->wpids && data->wpids->index)
		status = ft_killpids(data->wpids);
	if (data->ast)
  {
		ft_free_ast(data->ast);
    data->ast = NULL;
  }
	status = ft_restore_std(STDIN_FILENO, O_RDONLY, status);
	if (data->fd[0] != STDIN_FILENO)
		close(data->fd[0]);
	status = ft_restore_std(STDOUT_FILENO, O_WRONLY, status);
	if (data->fd[1] != STDOUT_FILENO)
		close(data->fd[1]);
	return (status);
}
