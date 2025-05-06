/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:16:37 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/06 16:21:47 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h" 

int		exit_err(char *msg)
{
	// TODO: should free the memory
	perror(msg);
	exit(1);
}

void	next_token(t_token **lst)
{
	if (*lst && (*lst)->next)
		*lst = (*lst)->next;
}

int		match(t_token **lst, t_type tt)
{
	if (*lst && (*lst)->type == tt)
		return (next_token(lst), 1);
	return (0);
}
