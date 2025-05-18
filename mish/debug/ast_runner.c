#include "./debug.h"

char **ft_split_paths(char *str);
t_data *init_example_data(char **envp);
char **ft_get_paths(char **environ);


t_mish mish;
int main(int ac, char **av, char **envp) {
  (void )ac, (void)av;
	t_data *data = init_example_data(envp);
	if (!data) return 1;

	t_ast *ast = example_list_1();
  mish.envp = envp;
  mish.exit_status = 0;

	ft_executor(data, ast);
  ft_waitpids(data->wpids);

	return 0;
}
// ---------- MAIN ---------- //
// Simple split by colon ':'
char **ft_split_paths(char *str)
{
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

t_data *init_example_data(char **envp)
{
	t_data *data = calloc(1, sizeof(t_data));
	if (!data) return NULL;
	data->paths = ft_get_paths(envp);
	data->fd[0] = STDIN_FILENO;
	data->fd[1] = STDOUT_FILENO;
	data->wpids = arr_new();
	return data;
}

