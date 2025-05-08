/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:51:24 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/08 10:01:32 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

// OR => AND => PIPE => REDIR => WORD => LIST

t_ast	*parse_or(t_token **lst)
{
	t_ast	**left = parse_and(lst);
	while (
}

/*t_ast	*parse_and(t_token **lst)
t_ast	*parse_pipe(t_token **lst)
t_ast	*parse_redir(t_token **lst)
t_ast	*parse_word(t_token **lst)
t_ast	*parse_list(t_token **lst)
*/
