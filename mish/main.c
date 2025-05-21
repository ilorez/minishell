
#include "debug/debug.h"
#include "setup.h"
#include "utils.h"


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

int	main(int ac, char **av, char **env)
{
	t_token	*token;
	char	*input;
  t_data *data;
  t_ast *ast;

  data = NULL;
  signal(SIGQUIT, SIG_IGN);
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		perror("signal\n");
	}
	init_history();
  ft_setup_mish(ac, av, env);
	while (1)
	{
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
			ast = example_list_1();
      data = ft_setup_data(data, ast);
      g_mish.exit_status = ft_executor(data, ast);
      ft_waitpids(data->wpids);
      handel_cmd_end(data);
		}
		free(input);
	}
  ft_free_all(&data);
	return (g_mish.exit_status);
}
