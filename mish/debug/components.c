
#include "./debug.h"

t_ast *ex_bi(t_type type, t_ast *left, t_ast *right) {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = type;
	ast->left = left;
	ast->right = right;
	return ast;
}

t_ast *ex_redir(char *file_name, int fd, int flags, t_ast *next_ast) {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

  // create redir type
	t_redir *redir = calloc(1, sizeof(t_redir));
  if (!redir)
    return (free(ast), NULL);
	redir->fpath = ft_strdup(file_name);
	redir->fd = fd;
	redir->flags = flags;
	redir->mode = 0644;

	ast->type = T_REDIR;
	ast->redir = redir;
	ast->left = next_ast;
	return ast;
}

t_ast *ex_subshell(t_ast *argast) {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_SUBSH;
	ast->left = argast;
	return ast;
}

t_ast *ex_exec(char *cmd)
{
  t_ast *ast;

  ast = calloc(1, sizeof(t_ast));
	ast->type = T_EXEC;
	ast->argv = ft_split(ft_strdup(cmd), ' ');
  return (ast);
}
