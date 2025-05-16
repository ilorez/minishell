/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:16:37 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/16 14:18:46 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

int	match_redir(t_token **lst)
{
	return (match(lst, T_LESS) || match(lst, T_LLESS) ||match(lst, T_GREAT)||match(lst, T_GGREAT));
}

t_redir		*fill_redir(t_token **lst)
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
		redir->flags = O_RDONLY;
		redir->mode = 644;
		return (redir);
	}
	return (ft_heredoc(str));
}

void	next_token(t_token **lst)
{
	if (*lst)
		*lst = (*lst)->next;
}

int	match(t_token **lst, t_type tt)
{
	if (*lst && (*lst)->type == tt)
		return (1);
	return (0);
}

t_ast	*new_node(t_type tt, void *value, t_ast *r, t_ast *l)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = tt;
	if (tt == T_REDIR)
		node->redir = (t_redir *)value;
	else
		node->argv = (char **)value;
	node->right = r;
	node->left = l;
	return (node);
}
