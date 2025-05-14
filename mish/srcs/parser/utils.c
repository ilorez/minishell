/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:16:37 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/14 19:58:23 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

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

t_ast	*new_node(t_type tt, void **value, t_ast *r, t_ast *l)
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
