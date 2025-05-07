/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:03:54 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/07 15:41:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

int ft_executor(t_data *data, t_ast *ast)
{
  int status;
  
  if (!ast || ast->type == T_EOL)
    return (0);
  if (ast->type == T_OR)
  {
    status = ft_executor(data, ast->left);
    if (status != 0)
      status = ft_executor(data, ast->right);
  }
  else if (ast->type == T_AND)
  {
    status = ft_executor(data, ast->left);
    if (status == 0)
      status = ft_executor(data, ast->right);
  }
  else if (ast->type == T_PIPE)
  {
    // TODO: PIPE
  }
  else if (ast->type == T_SUBSH)
    status = ft_executor(data, ast->left);
  else if (ast->type == T_REDIR)
  {
    // TODO: redirect 
    // ft_redirect((t_redir *)ast->value);
    status = ft_executor(data, ast->left);
  }
  else if (ast->type == T_EXEC)
  {
    // TODO: execute
  }
  return (status);
}
