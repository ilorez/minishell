/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:57:09 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/14 14:02:18 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

// ANSI color codes
#define C_RESET     "\033[0m"
#define C_YELLOW    "\033[1;33m"
#define C_GREEN     "\033[1;32m"
#define C_CYAN      "\033[1;36m"

// Helper function to print indentation
static void	print_indent(int level)
{
	for (int i = 0; i < level; i++)
		printf("  ");
}

// Convert enum type to string
static const char	*get_type_str(t_type type)
{
	switch (type)
	{
		case T_EXEC: return "T_EXEC";
		case T_REDIR: return "T_REDIR";
		case T_PIPE: return "T_PIPE";
		case T_AND: return "T_AND";
		case T_OR: return "T_OR";
		case T_SUBSH: return "T_SUBSH";
		case T_ROOT: return "T_ROOT";
		default: return "UNKNOWN";
	}
}

// Recursive function to print AST
void	print_ast(t_ast *node, int level)
{
	if (!node)
		return;
	print_indent(level);
	printf(C_YELLOW "Node Type: %s\n" C_RESET, get_type_str(node->type));

	if (node->type == T_EXEC && node->argv)
	{
		print_indent(level + 1);
		printf(C_GREEN "ARGV: ");
		for (int i = 0; node->argv[i]; i++)
			printf("\"%s\" ", node->argv[i]);
		printf(C_RESET "\n");
	}
	else if (node->type == T_REDIR && node->redir)
	{
		print_indent(level + 1);
		printf(C_CYAN "Redirection: fpath=\"%s\", fd=%d, flags=%d, mode=%d\n" C_RESET,
				node->redir->fpath, node->redir->fd,
				node->redir->flags, node->redir->mode);
	}
	print_ast(node->left, level + 1);
	print_ast(node->right, level + 1);
}

