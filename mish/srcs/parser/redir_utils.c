/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:16:37 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/27 11:48:58 by znajdaou         ###   ########.fr       */
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
	while (match(lst, T_WORD))
		next_token(lst);
	if (match_redir(lst))
	{
		redir = fill_redir(lst);
		node = consume_redir(lst);
		node = new_node(T_REDIR, redir, NULL, node);
	}
	return (node);
}

int	match_redir(t_token **lst)
{
	if (!lst || !*lst)
		return (0);
	return ((*lst)->type >= T_LESS && (*lst)->type <= T_GGREAT);
}

t_redir	*fill_redir(t_token **lst)
{
	t_redir	*redir;
	t_type	tt;
	char	*str;

	tt = (*lst)->type;
	next_token(lst);
	str = ft_calloc((*lst)->word->len + 1, sizeof(char));
	if (!str)
		exit_err("malloc failed", 2);
	ft_strlcpy(str, (*lst)->word->ptr, (*lst)->word->len + 1);
	next_token(lst);
	if (tt != T_LLESS)
	{
		redir = ft_calloc(1, sizeof(t_redir));
		if (!redir)
			exit_err("malloc failed fill_redir", 2);
		redir->fpath = str;
		redir->fd = 1 * (tt == T_GREAT || tt == T_GGREAT);
		if (tt == T_LESS)
			redir->flags = O_RDONLY;
		else
			redir->flags = O_WRONLY | O_CREAT | O_APPEND * (tt == T_GGREAT);
		redir->mode = 0644;
		return (redir);
	}
	return (ft_heredoc(str));
}
