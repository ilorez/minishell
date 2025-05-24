/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:16:37 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/17 09:47:46 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_ast	*consume_redir(t_token **lst, int count)
{
	t_ast	*node;
	t_redir	*redir;

	if (!lst || !*lst || count == 0)
		return (NULL);
	node = NULL;
	if (match_redir(lst))
	{
		redir = fill_redir(lst);
		node = consume_redir(lst, count - 1);
		node = new_node(T_REDIR, redir, NULL, node);
	}
	else if (count)
	{
		next_token(lst);
		node = consume_redir(lst, count - 1);
	}
	return (node);
}

void	add_back_node(t_ast *lst, t_ast *end)
{
	if (lst)
	{
		while(lst->left)
			lst = lst->left;
		lst->left = end;
	}
	else
		lst = end;

}

int	is_redir(t_token *lst)
{
	int count;

	count = 0;
	while (lst->type >= T_LESS && lst->type <= T_WORD)
	{
		if (lst->type >= T_LESS && lst->type <= T_GGREAT)
			count++;
		lst = lst->next;
	}
	return (count);
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
	consume_node(lst);
	str = ft_calloc((*lst)->word->len + 1, sizeof(char));
	if (!str)
		exit_err("malloc failed", 2);
	ft_strlcpy(str, (*lst)->word->ptr, (*lst)->word->len + 1);
	consume_node(lst);
	if (tt != T_LLESS)
	{
		redir = ft_calloc(1, sizeof(t_redir));
		if (!redir)
			exit_err("malloc failed fill_redir", 2);
		redir->fpath = str;
		redir->fd = 1 * (tt == T_GREAT || tt == T_GGREAT);
		redir->flags = O_RDONLY;
		redir->mode = 0644;
		return (redir);
	}
	return (ft_heredoc(str));
}
