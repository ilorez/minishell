#include "./debug.h"

int main(int ac, char **av, char **envp)
{
  t_ast *ast;
  t_data *data;

  data = NULL;
  ft_setup_mish(ac, av, envp);
	ast = ex_bi(T_OR, ex_bi(T_AND, ex_exec("echo hi"), ex_exec("echo hi2")), ex_exec("echo hi3"));
  data = ft_setup_data(data, ast);
	ft_executor(data, data->ast);
  ft_waitpids(data->wpids);
  ft_free_all(&data);
	return (g_mish.exit_status);
}

