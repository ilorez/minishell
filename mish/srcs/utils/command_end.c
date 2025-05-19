/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:18:05 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/19 10:29:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

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

int	handel_cmd_end(t_data *data)
{
	int	status;

	status = 0;
	if (!data)
		return (0);
	if (data->wpids->index)
		status = ft_killpids(data->wpids);
	if (data->ast)
		; //TODO: ft_free_ast(data->ast);
	status = ft_restore_std(STDIN_FILENO, O_RDONLY, status);
	if (data->fd[0] != STDIN_FILENO)
		close(data->fd[0]);
	status = ft_restore_std(STDOUT_FILENO, O_WRONLY, status);
	if (data->fd[1] != STDOUT_FILENO)
		close(data->fd[1]);
	return (status);
}
