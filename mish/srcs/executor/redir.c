/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:36:39 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 18:40:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

int	_open_fialed_case(t_data *data)
{
	int	*status;

	status = ft_calloc(1, sizeof(int));
	if (!status)
		return (ft_perror(NULL, ERR_MALLOC_FAIL), 1);
	*status = -1;
	arr_append(data->wpids, status);
	return (perror("open"), 1);
}

int	ft_redir(t_data *data, t_ast *ast, t_redir *r)
{
	int		fd;
	t_arr	*lst;
	int		org;
	int		exec_status;

	if (!r)
		return (ft_executor(data, ast->left));
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
		return (_open_fialed_case(data));
	org = data->fd[r->fd];
	data->fd[r->fd] = fd;
	exec_status = ft_executor(data, ast->left);
	close(fd);
	data->fd[r->fd] = org;
	return (exec_status);
}
