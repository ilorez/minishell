
#include "debug/debug.h"
#include "setup.h"
#include "utils.h"
#include <signal.h>


void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n");           // Move to a new line
	rl_on_new_line();       // Regenerate the prompt on a newline
	rl_replace_line("", 0); // Clear the previous text
	rl_redisplay();
	// TODO: stop running process
}

void	init_history(void)
{
	rl_clear_history();
	//add_history("first command");
}


void	handle_sigint2(int sig)
{
	(void)sig;
	printf("\n");           // Move to a new line
	//printf("hello\n");           // Move to a new line
	//rl_on_new_line();       // Regenerate the prompt on a newline
	//rl_replace_line("", 0); // Clear the previous text
	//rl_redisplay();
	// TODO: stop running process
}
int	main(int ac, char **av, char **env)
{
	t_token	*token;
	char	*input;
  t_data *data;
  t_ast *ast;

  data = NULL;
  signal(SIGQUIT, SIG_IGN);
	init_history();
  ft_setup_mish(ac, av, env);
	while (1)
	{
	  if (signal(SIGINT, handle_sigint) == SIG_ERR)
		  perror("signal\n");
		input = readline("minishell$");
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			token = ft_get_tokens(input);
			print_tokens(token);
      // grammer
      // parser
			ft_free_tokens(&token);
      // echo hi && ehco hi2 || echo hi3
			ast = ex_bi(T_OR, ex_bi(T_AND, ex_exec("echo hi"), ex_exec("echo hi2")), ex_exec("echo hi3"));
      data = ft_setup_data(data, ast);
      signal(SIGINT, handle_sigint2);
      g_mish.exit_status = ft_executor(data, ast);
      ft_waitpids(data->wpids);
      handel_cmd_end(data);
		}
		free(input);
	}
  ft_free_all(&data);
	return (g_mish.exit_status);
}
