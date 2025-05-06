/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:00:00 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/06 16:21:06 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"


static t_type	command(t_token **lst);
int		exit_err(char *msg);
void	next_token(t_token **lst);
int		match(t_token **lst, t_type tt);

int	ft_grammar(t_token *lst)
{
	if (!command(&lst))
		exit_err("syntax error!\n");
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
			exit_err("nothing after '('\n");
		if (!match(lst, T_RPAR))
			exit_err("unclosed '('\n");
	else if (match(lst, T_WORD))
	{
		while (match(lst, T_WORD))
		;
		if (match(lst, T_AND) || match(lst, T_OR) || match(lst, T_PIPE)
			|| match(lst, T_REDIR))
			if (!command(lst))
				exit_err("expected a command after an operator\n");
	}
	else
		return (0);
	return (1);
}
