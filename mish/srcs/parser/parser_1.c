/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:13:56 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/13 21:15:09 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_ast	*parse_list(t_token **lst)
{
	t_ast	*left;

	left = parse_or(lst);
	return (new_node(T_SUBSH, NULL, NULL, left));
}
