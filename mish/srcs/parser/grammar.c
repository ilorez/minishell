/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:00:00 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/14 16:22:10 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

// static int	_print_err(int err_n);

int	ft_grammar(t_token *lst)
{
	if (!lst)
		return (ft_perror("empty input", ERR_SYNTAX), 1);
	if (match_op(&lst, 0))
		return (ft_perror("unexpected operator at start", ERR_SYNTAX), 1);
	if (ft_operators(&lst))
		return (1);
	if (lst != NULL)
		return (ft_perror("unexpected token at end", ERR_SYNTAX), 1);
	return (0);
}

int	ft_operators(t_token **lst)
{
	if (ft_parenthese(lst) && ft_command(lst))
		return (ft_perror("expected command or (", ERR_SYNTAX), 1);
	while (match_op(lst, 0))
	{
		next_token(lst);
		if (ft_parenthese(lst) && ft_command(lst))
			return (ft_perror("expected command after operator", ERR_SYNTAX),
				1);
	}
	return (0);
}

int	ft_parenthese(t_token **lst)
{
	if (!match(lst, T_LPAR))
		return (1);
	next_token(lst);
	if (ft_operators(lst))
		return (1);
	if (!match(lst, T_RPAR))
		return (ft_perror("expected )", ERR_SYNTAX), 1);
	next_token(lst);
	if (match(lst, T_WORD))
		return (ft_perror("unexpected token after )", ERR_SYNTAX), 1);
	while (match_op(lst, 1))
	{
		next_token(lst);
		if (!match(lst, T_WORD))
			return (ft_perror("unexpected token near redir", ERR_SYNTAX), 1);
		next_token(lst);
	}
	return (0);
}

int	ft_command(t_token **lst)
{
	int	success;

	success = 1;
	while (match(lst, T_WORD) || match_op(lst, 1))
	{
		if (match(lst, T_WORD))
		{
			next_token(lst);
		}
		else if (match_op(lst, 1))
		{
			next_token(lst);
			if (!match(lst, T_WORD))
				return (ft_perror("expected word after redirection",
						ERR_SYNTAX), 1);
			next_token(lst);
		}
		success = 0;
	}
	return (success);
}

/*static int	_print_err(int err_n)
{
return (ft_perror("expected word after redirection", ERR_SYNTAX), 1);
return (ft_perror("unexpected token near redir", ERR_SYNTAX), 1);
return (ft_perror("unexpected token after )", ERR_SYNTAX), 1);
return (ft_perror("expected )", ERR_SYNTAX), 1);
return (ft_perror("expected command after operator", ERR_SYNTAX), 1);
return (ft_perror("expected command or (", ERR_SYNTAX), 1);
	return (0);
}*/
