/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:56:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/06/01 15:01:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "container.h"
#include "setup.h"
#include "t_arr.h"
#include <stdlib.h>
#include <unistd.h>

static void	_here_doc(char *file, char *eof);

int	ft_open_hds(t_ast *ast, t_ast *head)
{
	if (!ast)
		return (0);
	else if (ast->type == T_AND || ast->type == T_OR || ast->type == T_PIPE)
	{
		if (!ft_open_hds(ast->left, head))
			return (0);
		return (ft_open_hds(ast->right, head));
	}
	else if (ast->type == T_SUBSH)
		return (ft_open_hds(ast->left, head));
	else if (ast->type == T_REDIR)
	{
		if (ast->redir->is_hd)
			if (!ft_heredoc(ast->redir, head))
				return (0);
		return (ft_open_hds(ast->left, head));
	}
	return (1);
}

int	ft_heredoc(t_redir *r, t_ast *ast)
{
	int (pid), (status);
	char *(file), *(eof);
	file = ft_randtmp_file("/tmp/", "mish_herdoc_");
	eof = ft_strdup(r->fpath);
	if (!file)
		return (0);
	pid = fork();
	if (pid == -1)
		return (free(file), perror("fork"), 0);
	else if (pid == 0)
	{
		r->is_hd = 0;
		ft_free_ast(ast);
		arr_clean(&g_mish.envp);
		_here_doc(file, eof);
	}
	free(r->fpath);
	free(eof);
	r->fpath = file;
	status = 0;
	waitpid(pid, &status, 0);
	ft_check_status(status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (0);
	return (1);
}

static void	_exit_hd(char *eof, int fd, int cmd)
{
	static char	*seof;
	static int	sfd;

	if (cmd == 0)
	{
		seof = eof;
		sfd = fd;
	}
	else if (cmd == 1)
	{
		free(seof);
		close(sfd);
	}
}

// here there is a probleme some info eof is not freed before exit
void	handel_herdocsig(int sig)
{
	(void)sig;
	_exit_hd(NULL, 0, 1);
	exit(130);
}

static void	_here_doc(char *file, char *eof)
{
	char	*line;
	size_t	hd_s;
	size_t	line_s;
	int		fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	free(file);
	signal(SIGINT, handel_herdocsig);
	if (fd == -1)
		return (perror("open"));
	_exit_hd(eof, fd, 0);
	line = readline(">");
	hd_s = ft_strlen(eof);
	line_s = ft_strlen(line);
	while (line && !(ft_strncmp(eof, line, hd_s) == 0 && line_s == hd_s))
	{
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
		line = readline(">");
		line_s = ft_strlen(line);
	}
	free(line);
	_exit_hd(NULL, 0, 1);
	exit(0);
}
