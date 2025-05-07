/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:16:07 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/07 13:01:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

void	ft_free_tokens(t_token **tks)
{
	t_token	*tmp;

	if (!(*tks))
		return ;
	while ((*tks))
	{
		tmp = (*tks)->next;
		if ((*tks)->type == T_WORD && (*tks)->word)
			free((*tks)->word);
		free((*tks));
		(*tks) = tmp;
	}
}
