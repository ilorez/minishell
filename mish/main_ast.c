
#include "container.h"
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
	add_history("first command");
}

int	main(int ac, char **av, char **env)
{
	t_token	*token;
	t_ast	*ast;
	char	*input;
	t_data *data;

	// setup data and envirnoment varibale
	// using ft_setup() form ./setup/setup.c
	// the setup it's free memory and exit auto on error
	ft_setup_mish(ac, av, env);
	(void)ac, (void)av, (void)env;
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		printf("failed to register interrupts with kernel\n");
	}
	init_history();
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			token = ft_get_tokens(input);
			//		print_tokens(token);
			if (!ft_grammar(token))
			{
				ast = ft_parse_ast(&token);
				//print_ast(ast, 0);
				data = ft_setup_data(ast);
				ft_executor(data, ast);
				ft_waitpids(data->wpids);
			}
			ft_free_tokens(&token);
			// send AST to exector
			// executor return a status put it in $? variable
			// done
		}
		free(input);
	}
	ft_free_all(data);
	return (0);
}
