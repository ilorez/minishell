/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:12:46 by abdnasse          #+#    #+#             */
/*   Updated: 2025/06/01 14:58:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_ast	*ft_parse_ast(t_token **lst)
{
	t_token	*lst_copy;
	t_ast	*ast;

	lst_copy = *lst;
	ast = parse_or_and(lst);
	ft_free_tokens(&lst_copy);
	if (!ft_open_hds(ast, ast))
	{
		ft_free_ast(ast);
		ast = NULL;
	}
	return (ast);
}

t_ast	*parse_or_and(t_token **lst)
{
	t_ast	*left;
	t_ast	*right;
	t_type	type;

	left = parse_pipe(lst);
	while (match(lst, T_OR) || match(lst, T_AND))
	{
		type = T_AND;
		if (match(lst, T_OR))
			type = T_OR;
		next_token(lst);
		right = parse_pipe(lst);
		left = new_node(type, NULL, right, left);
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
	t_ast	*word;
	t_token	*copy_lst;

	copy_lst = *lst;
	word = parse_word(lst);
	if (word && word->type == T_SUBSH)
		left = consume_redir(lst);
	else
		left = consume_redir(&copy_lst);
	left = add_back_node(left, word);
	return (left);
}
