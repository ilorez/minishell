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

static int	match_op(t_token **lst);
//TODO: its is possible to start with rediraction then a command after 
int	ft_grammar(t_token **lst)
{
	if (match(lst, T_LPAR))
	{
		next_token(lst, 'n');
		if (ft_grammar(lst))
			return (1);
		if (match(lst, T_RPAR))
			return (next_token(lst, 'n'), 0);
		else 
			return (ft_perror("expected ) ", ERR_SYNTAX), 1);
	}
	if (!match(lst, T_WORD))
		return (ft_perror("expected word ", ERR_SYNTAX), 1);
	while (match(lst, T_WORD))
		next_token(lst, 'n');
	if (match_op(lst))
	{
		next_token(lst, 'n');
		if (ft_grammar(lst))
			return (1);
	}
	else if (!*lst || match(lst, T_RPAR))
		return (0);
	else
		return (ft_perror("unexpected token ", ERR_SYNTAX), 1);
	return (0);
}

static int	match_op(t_token **lst)
{
	t_type	tt;

	if (!lst || !*lst)
		return (0);
	tt = (*lst)->type;
	return (tt >= T_AND && tt <= T_GGREAT);
}

t_ast	*ft_parse_ast(t_token **lst)
{
	if (match(lst, T_ROOT))
		next_token(lst, 'p');
	return (parse_or(lst));
}
