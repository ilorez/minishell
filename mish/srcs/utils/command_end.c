/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:18:05 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 10:55:40 by znajdaou         ###   ########.fr       */
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
		if (ast->redir->is_hd)
			unlink(ast->redir->fpath);
		free(ast->redir->fpath);
		free(ast->redir);
		ft_free_ast(ast->left);
	}
	free(ast);
}

int	ft_killpids(t_arr *pid)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (++i < pid->index)
	{
		if (*(int *)(pid->content[i]) <= 0)
			continue ;
		kill(*(int *)(pid->content[i]), SIGTERM);
	}
	arr_empty(pid);
	return (status);
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
