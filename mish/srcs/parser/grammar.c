/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:00:00 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/04 12:21:34 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

int		ft_grammar(t_token **lst)
{
	t_type tt;

	if (lst->next)
	{
		tt = lst->type;
		if (tt == T_LPAR)

		lst = lst->next;
	}
}
