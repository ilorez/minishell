#include "../includes/container.h"
#include <fcntl.h>
#include <stdlib.h>

// ---------- AST EXAMPLES ---------- //

t_ast *example1() {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_AND;

	ast->left = calloc(1, sizeof(t_ast));
	ast->left->type = T_EXEC;
	ast->left->argv = ft_split(ft_strdup("echo hi"), ' ');

	ast->right = calloc(1, sizeof(t_ast));
	ast->right->type = T_EXEC;
	ast->right->argv = ft_split(ft_strdup("cat -e"), ' ');

	return ast;
}

t_ast *example2() {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	t_redir *redir = calloc(1, sizeof(t_redir));
	redir->fpath = ft_strdup("./in2");
	redir->fd = 0;
	redir->flags = O_RDONLY;
	redir->mode = 0644;

	char **argv = ft_split(ft_strdup("cat -e"), ' ');

	ast->type = T_REDIR;
	ast->redir = redir;

	ast->left = calloc(1, sizeof(t_ast));
	ast->left->type = T_EXEC;
	ast->left->argv = argv;

	return ast;
}

t_ast *example2_1() {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	t_redir *redir = calloc(1, sizeof(t_redir));
	redir->fpath = ft_strdup("./out");
	redir->fd = 1;
	redir->flags = O_WRONLY | O_CREAT;
	redir->mode = 0644;

	char **argv = ft_split(ft_strdup("cat -e"), ' ');

	ast->type = T_REDIR;
	ast->redir = redir;

	ast->left = calloc(1, sizeof(t_ast));
	ast->left->type = T_EXEC;
	ast->left->argv = argv;

	return ast;
}

t_ast *example3() {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_PIPE;
	ast->left = calloc(1, sizeof(t_ast));
	ast->left->type = T_EXEC;
	ast->left->argv = ft_split(ft_strdup("ls"), ' ');

	ast->right = calloc(1, sizeof(t_ast));
	ast->right->type = T_EXEC;
	ast->right->argv = ft_split(ft_strdup("cat -e"), ' ');

	return ast;
}
t_ast *example_pipe(char *cmd1, char *cmd2) {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_PIPE;
	ast->left = calloc(1, sizeof(t_ast));
	ast->left->type = T_EXEC;
	ast->left->argv = ft_split(ft_strdup(cmd1), ' ');

	ast->right = calloc(1, sizeof(t_ast));
	ast->right->type = T_EXEC;
	ast->right->argv = ft_split(ft_strdup(cmd2), ' ');

	return ast;
}

t_ast *example4(char *cmd1, char *cmd2) {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_PIPE;
	ast->left = example_pipe(cmd1, cmd2);
	ast->right = example_pipe(cmd2, cmd2);
	return ast;
}

t_ast *example_pipe_redir() {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_PIPE;
	ast->left = example2();
	ast->right = example2_1();
	return ast;
}

t_ast *example_subshell() {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_SUBSH;
	ast->left = example1();
	return ast;
}

t_ast *example_exec(char *cmd)
{
  t_ast *ast;

  ast = calloc(1, sizeof(t_ast));
	ast->type = T_EXEC;
	ast->argv = ft_split(ft_strdup(cmd), ' ');
  return (ast);
}

t_ast *example5() {
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

	ast->type = T_PIPE;
	ast->left = example_exec("sleep 3");
	ast->right = example_subshell();
	return ast;
}


// ---------- MAIN ---------- //
// Simple split by colon ':'
char **ft_split_paths(char *str) {
	int count = 1;
	for (char *tmp = str; *tmp; tmp++)
		if (*tmp == ':') count++;

	char **res = calloc(count + 1, sizeof(char *));
	if (!res) return NULL;

	int i = 0;
	char *token = strtok(str, ":");
	while (token) {
		res[i++] = ft_strdup(token);
		token = strtok(NULL, ":");
	}
	return res;
}

char **ft_get_paths(char **environ) {
	for (int i = 0; environ[i]; i++) {
		if (strncmp(environ[i], "PATH=", 5) == 0) {
			return ft_split_paths(environ[i] + 5);
		}
	}
	return NULL;
}

t_data *init_example_data(char **envp) {
	t_data *data = calloc(1, sizeof(t_data));
	if (!data) return NULL;
	data->curr_dir = ft_strdup("/tmp");
	data->paths = ft_get_paths(envp);
	data->envp = envp;
	data->fd[0] = STDIN_FILENO;
	data->fd[1] = STDOUT_FILENO;
	data->wpids = arr_new();
	return data;
}

int main(int ac, char **av, char **envp) {
  (void )ac, (void)av;
	t_data *data = init_example_data(envp);
	if (!data) return 1;

	t_ast *ast = example5(); // Change to example2() to test redirection

	ft_executor(data, ast);
  ft_waitpids(data->wpids);

	return 0;
}
