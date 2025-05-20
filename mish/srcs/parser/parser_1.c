/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:13:56 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/14 19:36:13 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_ast	*parse_list(t_token **lst)
{
	t_ast	*left;

	next_token(lst, 'p');
	left = parse_or(lst);
	next_token(lst, 'p');
	return (new_node(T_SUBSH, NULL, NULL, left));
}
