/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:12:46 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/14 16:41:07 by abdnasse         ###   ########.fr       */
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
		next_token(lst);
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
		next_token(lst);
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
		next_token(lst);
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
		next_token(lst);
		right = parse_word(lst);
		left = new_node(T_REDIR, NULL, right, left);
	}
	return (left);
}

t_ast	*parse_word(t_token **lst)
{
	t_arr	*exec;
	char	*arg;

	if (match(lst, T_LPAR))
		return (parse_list(lst));
	exec = arr_new();
	while (match(lst, T_WORD))
	{
		arg = (char *)malloc(((*lst)->word->len + 1) * sizeof(char));
		if (!arg)
			exit_err("malloc failed", 2);
		ft_strlcpy(arg, (*lst)->word->ptr, (*lst)->word->len + 1);
		arr_append(exec, arg);
		next_token(lst);
	}
	return (new_node(T_EXEC, exec->content, NULL, NULL));
}
