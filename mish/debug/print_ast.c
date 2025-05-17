/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:57:09 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/16 14:29:45 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

// ANSI color codes
#define C_RESET     "\033[0m"
#define C_YELLOW    "\033[1;33m"
#define C_GREEN     "\033[1;32m"
#define C_CYAN      "\033[1;36m"

// Tree drawing helpers
static void	print_prefix(int level, int is_right)
{
	for (int i = 0; i < level - 1; i++)
		printf("│   ");
	if (level > 0)
		printf("%s── ", is_right ? "└" : "├");
}

const char	*get_type_str(t_type type)
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

void	print_ast(t_ast *node, int level)
{
	if (!node)
		return;

	// Identify if it's a right child for tree drawing
	int is_leaf = (!node->left && !node->right);

	// Pick color based on type
	const char *color = C_YELLOW;
	if (node->type == T_EXEC)
		color = C_GREEN;
	else if (node->type == T_REDIR)
		color = C_CYAN;

	print_prefix(level, is_leaf);
	printf("%s%s%s\n", color, get_type_str(node->type), C_RESET);

	if (node->type == T_EXEC && node->argv)
	{
		print_prefix(level + 1, 1);
		printf(C_GREEN "ARGV: ");
		for (int i = 0; node->argv[i]; i++)
			printf("|%s| ", node->argv[i]);
		printf(C_RESET "\n");
	}
	else if (node->type == T_REDIR && node->redir)
	{
		print_prefix(level + 1, 1);
		printf(C_CYAN "fpath=\"%s\", fd=%d, flags=%d, mode=%d" C_RESET "\n",
				node->redir->fpath,
				node->redir->fd,
				node->redir->flags,
				node->redir->mode);
	}

	if (node->left)
		print_ast(node->left, level + 1);
	if (node->right)
		print_ast(node->right, level + 1);
}

