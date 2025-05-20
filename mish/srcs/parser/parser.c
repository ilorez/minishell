/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:12:46 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/17 09:41:21 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_ast	*ft_parse_ast(t_token **lst)
{
	t_ast	*ast;
	
	ast = parse_or_and(lst);
	return (ast);
}

t_ast	*parse_or_and(t_token **lst)
{
	t_ast	*left;
	t_ast	*right;
	t_type	type;

	right = parse_pipe(lst);
	while (match(lst, T_OR) || match(lst, T_AND))
	{
		if (match(lst, T_OR))
			type = T_OR;
		else
			type = T_AND;
		next_token(lst, 'p');
		left = parse_pipe(lst);
		right = new_node(type, NULL, right, left);
	}
	return (right);
}

t_ast	*parse_pipe(t_token **lst)
{
	t_ast	*left;
	t_ast	*right;

	right = parse_redir(lst);
	while (match(lst, T_PIPE))
	{
		next_token(lst, 'p');
		left = parse_redir(lst);
		right = new_node(T_PIPE, NULL, right, left);
	}
	return (right);
}

t_ast	*parse_redir(t_token **lst)
{
	t_ast	*left;
	t_redir	*redir;

	left = parse_word(lst);
	if (match_redir(lst))
	{
		left = parse_redir(lst);
		redir = fill_redir(lst);
		left = new_node(T_REDIR, redir, NULL, left);
	}
	return (left);
}
