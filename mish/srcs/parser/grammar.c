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

static int	match_op(t_token **lst, int is_redir);

int	ft_grammar(t_token **lst)
{
	if (match(lst, T_LPAR))
	{
		next_token(lst, 'n');
		if (ft_grammar(lst))
			return (1);
		if (!match(lst, T_RPAR))
			return (ft_perror("expected ) ", ERR_SYNTAX), 1);
		else 
			next_token(lst, 'n');
	}
	if(match
	if ((*lst)->prev && (*lst)->prev->type == T_RPAR && !match(lst, T_WORD))
		return (ft_perror("expected word ", ERR_SYNTAX), 1);
	//if (!match(lst, T_WORD) & !match_op(lst, 1))
	//	return (ft_perror("expected word ", ERR_SYNTAX), 1);
	if (match_op(lst, 0) || match_op(lst, 1))
	{
		next_token(lst, 'n');
		if (ft_grammar(lst))
			return (1);
	}
	while (match(lst, T_WORD))
		next_token(lst, 'n');
	return (0);
}

static int	match_op(t_token **lst, int is_redir)
{
	t_type	tt;

	if (!lst || !*lst)
		return (0);
	tt = (*lst)->type;
	if (is_redir)
		return (tt >= T_LESS && tt <= T_GGREAT);
	return (tt >= T_AND && tt <= T_PIPE);
}

t_ast	*ft_parse_ast(t_token **lst)
{
	if (match(lst, T_ROOT))
		next_token(lst, 'p');
	return (parse_or(lst));
}
