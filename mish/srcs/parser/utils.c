/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:16:37 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/10 14:00:46 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h" 

void	next_token(t_token **lst)
{
	if (*lst && (*lst)->next)
		*lst = (*lst)->next;
}

int		match(t_token **lst, t_type tt)
{
	if (*lst && (*lst)->type == tt)
		return (next_token(lst), 1);
	return (0);
}

//TODO: complete the function
t_ast	*new_node(t_type tt, void **value, t_ast *r, t_ast *l)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
		
}

