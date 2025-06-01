/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:13:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/27 20:21:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_free_data(t_data **data)
{
	if (!data || !*data)
		return ;
	handel_cmd_end(*data);
	if ((*data)->wpids)
		arr_clean(&((*data)->wpids));
	free(*data);
	*data = NULL;
}

void	ft_free_tokens(t_token **tks)
{
	t_token	*tmp;

	if (!(*tks))
		return ;
	while((*tks)->prev)
		*tks = (*tks)->prev;
	while ((*tks))
	{
		tmp = (*tks)->next;
		if ((*tks)->word && (*tks)->word)
			free((*tks)->word);
		free((*tks));
		(*tks) = tmp;
	}
}

void	ft_free_all(t_data **data)
{
	ft_free_data(data);
	arr_free(g_mish.envp);
	rl_clear_history();
}
