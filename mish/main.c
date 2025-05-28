
#include "./includes/setup.h"
#include <unistd.h>

void	handle_sigint(int sig)
{
	(void)sig;

	if (isatty(STDIN_FILENO))
	{
		if (g_mish.mode == M_INTRACTIVE)
		{
			write(STDOUT_FILENO, "\n", 1);
			rl_on_new_line();       // Regenerate the prompt on a newline
			rl_replace_line("", 0); // Clear the previous text
			rl_redisplay();
			g_mish.exit_status = 130;
		}
		else
			write(STDOUT_FILENO, "\n", 1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_token	*token;
	char	*input;
	t_data	*data;
	t_ast	*ast;

	data = NULL;
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
		perror("signal");
	signal(SIGQUIT, SIG_IGN);
	rl_clear_history();
	ft_setup_mish(ac, av, env);
	while (1)
	{
		g_mish.mode = M_INTRACTIVE;
		if (isatty(STDIN_FILENO))
			input = readline("mish> ");
		else 
			input = readline("");
		g_mish.mode = M_EXECUTION;
		if (!input)
			ft_exit(NULL, data);
		if (*input)
		{
			add_history(input);
			token = ft_get_tokens(input);
			// print_tokens(token);
			if (!ft_grammar(token))
			{
				ast = ft_parse_ast(&token);
				// print_ast(ast, 0);
				data = ft_setup_data(data, ast);
				ft_executor(data, ast);
				ft_waitpids(data->wpids);
				handel_cmd_end(data);
			}
			else
				ft_free_tokens(&token);
		}
		free(input);
	}
	ft_handel_exit(data, g_mish.exit_status);
}
