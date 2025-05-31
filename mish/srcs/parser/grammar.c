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
#include "t_errno.h"
#include <unistd.h>

static int	_print_err(int err_n);

int	ft_grammar(t_token *lst)
{
	int	old;

	old = g_mish.exit_status;
	g_mish.exit_status = 2;
	if (!lst)
		return (ft_perror("empty input", ERR_SYNTAX), 1);
	if (match_op(&lst, 0))
		return (ft_perror("unexpected operator at start", ERR_SYNTAX), 1);
	if (ft_operators(&lst))
		return (_print_err(0));
	if (lst != NULL)
		return (ft_perror("unexpected token at end", ERR_SYNTAX), 1);
	g_mish.exit_status = old;
	return (0);
}

int	ft_operators(t_token **lst)
{
	if (ft_parenthese(lst) && ft_command(lst))
		return (_print_err(6));
	while (match_op(lst, 0))
	{
		next_token(lst);
		if (ft_parenthese(lst) && ft_command(lst))
			return (_print_err(5));
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
		return (_print_err(4));
	next_token(lst);
	if (match(lst, T_WORD))
		return (_print_err(3));
	while (match_op(lst, 1))
	{
		next_token(lst);
		if (!match(lst, T_WORD))
			return (_print_err(2));
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
				return (_print_err(1));
			next_token(lst);
		}
		success = 0;
	}
	return (success);
}

static int	_print_err(int err_n)
{
	static int	err[7];
	static char	*list[7];

	list[0] = "print";
	list[1] = "expected word after redirection";
	list[2] = "unexpected token near redir";
	list[3] = "unexpected token after )";
	list[4] = "expected )";
	list[5] = "expected command after operator";
	list[6] = "expected command or (";
	if (err_n != 0)
	{
		if (err[err_n] != 1)
			err[err_n] = 1;
	}
	else
	{
		while (err_n < 7 && err[err_n] == 0)
			err_n++;
		ft_perror(list[err_n], ERR_SYNTAX);
	}
	return (1);
}
