/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:13:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 15:27:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	handel_cmd_end(data);
	if (data->envp)
		ft_free_str_lst(data->envp);
	if (data->paths)
		ft_free_str_lst(data->paths);
	if (data->curr_dir)
		free(data->curr_dir);
	if (data->wpids)
		arr_clean(&(data->wpids));
}

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
