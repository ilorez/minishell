/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:56:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/27 12:12:59 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <stdlib.h>

static void	_here_doc(char *file, char *eof);
static char	*_randtmp_file(char *dir, char *prefix);

t_redir	*ft_heredoc(char *eof)
{
	t_redir	*r;
	int		pid;
	char	*file;
	int		status;

	file = _randtmp_file("/tmp/", "mish_herdoc_");
  if (!file)
    return (NULL);
	pid = fork();
	if (pid == -1)
		return (unlink(file), free(file), perror("fork"), NULL);
	else if (pid == 0)
		_here_doc(file, eof);
	r = ft_calloc(1, sizeof(t_redir));
	if (!r)
		return (ft_perror("heredoc", ERR_MALLOC_FAIL), NULL);
	r->fpath = file;
	r->fd = 0;
	r->flags = O_RDONLY;
	r->mode = 0644;
	r->is_hd = 1;
	free(eof);
	status = 0;
	waitpid(pid, &status, 0);
	ft_check_status(status);
  if (WIFSIGNALED(status))
    return (free(file), free(r), NULL);
	return (r);
}

static char	*_randtmp_file(char *dir, char *prefix)
{
	char	*random;
	char	*path;

	random = ft_itoa((unsigned long)(&tmpfile));
	if (!random)
		return (NULL);
	path = ft_strjoin(dir, random, prefix);
	free(random);
	return (path);
}

// here there is a probleme some info eof is not freed before exit
void	handel_herdocsig(int sig)
{
	(void)sig;
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
		return (perror("open filed"));
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
	close(fd);
	free(eof);
	exit(0);
}
