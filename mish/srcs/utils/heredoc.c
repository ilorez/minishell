/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:56:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/22 22:17:54 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <fcntl.h>

static void	_here_doc(int fd, char *eof);
static char	*_randtmp_file(char *dir, char *prefix);

t_redir	*ft_heredoc(char *eof)
{
	t_redir	*r;

	r = ft_calloc(1, sizeof(t_redir));
	if (!r)
	{
		ft_perror(NULL, ERR_MALLOC_FAIL);
		return (NULL);
	}
	r->fpath = _randtmp_file("/tmp/", "mish_herdoc_");
	r->fd = open(r->fpath, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (r->fd < 0)
	{
		perror("open failed");
		return (NULL);
	}
	_here_doc(r->fd, eof);
	r->fd = 0;
	r->flags = O_RDONLY;
	r->mode = 0644;
	free(eof);
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

static void	_here_doc(int fd, char *eof)
{
	char	*line;
	size_t	hd_s;
	size_t	line_s;

	line = readline(">");
	hd_s = ft_strlen(eof);
	line_s = ft_strlen(line);
	while (line && !(ft_strncmp(eof, line, hd_s) == 0 && line_s == hd_s))
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = readline(">");
		line_s = ft_strlen(line);
	}
	free(line);
	close(fd);
}
