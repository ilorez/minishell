/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:12:46 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/14 12:28:59 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_ast	*parse_or(t_token **lst)
{
	t_ast	*left;
	t_ast	*right;

	left = parse_and(lst);
	while (match(lst, T_OR))
	{
		right = parse_and(lst);
		left = new_node(T_OR, NULL, right, left);
	}
	return (left);
}

t_ast	*parse_and(t_token **lst)
{
	t_ast	*left;
	t_ast	*right;

	left = parse_pipe(lst);
	while (match(lst, T_AND))
	{
		right = parse_pipe(lst);
		left = new_node(T_AND, NULL, right, left);
	}
	return (left);
}

t_ast	*parse_pipe(t_token **lst)
{
	t_ast	*left;
	t_ast	*right;

	left = parse_redir(lst);
	while (match(lst, T_PIPE))
	{
		right = parse_redir(lst);
		left = new_node(T_PIPE, NULL, right, left);
	}
	return (left);
}

t_ast	*parse_redir(t_token **lst)
{
	t_ast	*left;
	t_ast	*right;

	left = parse_word(lst);
	while (match(lst, T_REDIR))
	{
		right = parse_word(lst);
		left = new_node(T_PIPE, NULL, right, left);
	}
	return (left);
}

t_ast	*parse_word(t_token **lst)
{
	t_arr	*exec;

	if (match(lst, T_LPAR))
		return (parse_list(lst));
	exec = arr_new();
	while (match(lst, T_WORD))
		arr_append(exec, (*lst)->word->ptr);
	return (new_node(T_EXEC, exec->content, NULL, NULL));
}
