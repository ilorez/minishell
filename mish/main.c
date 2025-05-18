
#include "container.h"
#include "debug/debug.h"
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

	if (signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		printf("failed to register interrupts with kernel\n");
	}
	init_history();
	while (1)
	{
		input = readline("minishell$");

    //ft_heredoc(input);
    //return (0);
		// Ctrl+D for exit
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			// printf("cmd: %s\n", input);
			token = ft_get_tokens(input);
			print_tokens(token);
			ft_free_tokens(&token);
			// send input to lexer
			// get tokenzation array
			// check if lexer has everthing done well
			// send tokenzation array to parser
			// check if parser do it's work with no error
			// get AST and check everthing has done well for parser with no error
			// send AST to exector
			// executor return a status put it in $? variable
			// done
		}
		free(input);
	}
	return (0);
}
