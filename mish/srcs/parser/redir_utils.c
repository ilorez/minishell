/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:16:37 by abdnasse          #+#    #+#             */
/*   Updated: 2025/06/01 14:56:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"
#include "parser.h"
#include "types.h"

t_ast	*consume_redir(t_token **lst)
{
	t_ast	*node;
	t_redir	*redir;

	if (!lst)
		return (NULL);
	node = NULL;
	redir = NULL;
	while (match(lst, T_WORD))
		next_token(lst);
	if (match_op(lst, 1))
	{
		redir = fill_redir(lst, redir);
		node = consume_redir(lst);
		node = new_node(T_REDIR, redir, NULL, node);
	}
	return (node);
}

int	match_op(t_token **lst, int is_redir)
{
	t_type	tt;

	if (!lst || !*lst)
		return (0);
	tt = (*lst)->type;
	if (is_redir)
		return (tt >= T_LESS && tt <= T_GGREAT);
	return (tt >= T_AND && tt <= T_PIPE);
}

t_redir	*fill_redir(t_token **lst, t_redir *redir)
{
	t_type	tt;
	char	*str;

	tt = (*lst)->type;
	next_token(lst);
	str = ft_calloc((*lst)->word->len + 1, sizeof(char));
	if (!str)
		exit_err("malloc failed", 2);
	ft_strlcpy(str, (*lst)->word->ptr, (*lst)->word->len + 1);
	next_token(lst);
	redir = ft_calloc(1, sizeof(t_redir));
	if (!redir)
		exit_err("malloc failed fill_redir", 2);
	redir->fpath = str;
	if (tt == T_LLESS)
		redir->is_hd = 1;
	redir->fd = 1 * (tt == T_GREAT || tt == T_GGREAT);
	if (tt == T_LESS || tt == T_LLESS)
		redir->flags = O_RDONLY;
	else
		redir->flags = O_WRONLY | O_CREAT | O_APPEND * (tt == T_GGREAT);
	redir->mode = 0644;
	return (redir);
}
