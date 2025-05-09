/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:51:24 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/09 11:12:09 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

// OR => AND => PIPE => REDIR => WORD => LIST

t_ast	*parse_or(t_token **lst)
{
	t_ast	**left;
	t_ast	**rihgt;

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
	t_ast	**left;
	t_ast	**rihgt;
	
	left = parse_pipe(lst);
	while (match(lst, T_AND))
	{
		right = parse_pipe(lst);
		left = new_node(T_AND, NULL, right, left);
	}
	return (left);
}

/*t_ast	*parse_pipe(t_token **lst)
t_ast	*parse_redir(t_token **lst)
t_ast	*parse_word(t_token **lst)
t_ast	*parse_list(t_token **lst)
*/
