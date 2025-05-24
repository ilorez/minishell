/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:18:05 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/24 15:37:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	else if (ast->type == T_AND || ast->type == T_OR || ast->type == T_PIPE)
	{
		ft_free_ast(ast->left);
		ft_free_ast(ast->right);
	}
	else if (ast->type == T_SUBSH)
		ft_free_ast(ast->left);
	else if (ast->type == T_EXEC)
		ft_free_str_lst(ast->argv);
	else if (ast->type == T_REDIR)
	{
		free(ast->redir->fpath);
		free(ast->redir);
		ft_free_ast(ast->left);
	}
	free(ast);
}

int	handel_cmd_end(t_data *data)
{
	int	status;

	status = 0;
	if (!data)
		return (0);
	if (data->wpids && data->wpids->index)
		status = ft_killpids(data->wpids);
	if (data->ast)
	{
		ft_free_ast(data->ast);
		data->ast = NULL;
	}
	return (status);
}
