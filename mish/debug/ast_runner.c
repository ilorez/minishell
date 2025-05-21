#include "./debug.h"

int main(int ac, char **av, char **envp)
{
  t_ast *ast;
  t_data *data;

  data = NULL;
  ft_setup_mish(ac, av, envp);
	ast = example_list_16();
  data = ft_setup_data(data, ast);
	ft_executor(data, data->ast);
  ft_waitpids(data->wpids);
  ft_free_all(data);
	return (g_mish.exit_status);
}

