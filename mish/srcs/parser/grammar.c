/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:00:00 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/09 11:30:12 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

static t_type	command(t_token **lst);

int	ft_grammar(t_token *lst)
{
	if (!command(&lst))
		exit_err("ft_grammer", ERR_SYNTAX);
	return (0);
}

t_ast	*ft_parse_ast(t_token **lst)
{
	return (parse_or(lst));
}

static t_type	command(t_token **lst)
{
	if (!*lst)
		return (0);
	if (match(lst, T_LPAR))
		if (!command(lst))
			exit_err("nothing after '('\n", ERR_SYNTAX);
	if (!match(lst, T_RPAR))
		exit_err("unclosed '('\n", ERR_SYNTAX);
	else if (match(lst, T_WORD))
	{
		while (match(lst, T_WORD))
			;
		if (match(lst, T_AND) || match(lst, T_OR) || match(lst, T_PIPE)
			|| match(lst, T_REDIR))
			if (!command(lst))
				exit_err("expected a command after an operator\n", ERR_SYNTAX);
	}
	else
		return (0);
	return (1);
}
