#include "./debug.h"

int main(int ac, char **av, char **envp)
{
  t_ast *ast;
  t_data *data;

  ft_setup_mish(ac, av, envp);
	ast = example_builtin_list_0();
  data = ft_setup_data(ast);
	ft_executor(data, data->ast);
  ft_waitpids(data->wpids);
  ft_free_all(data);
	return (mish.exit_status);
}

