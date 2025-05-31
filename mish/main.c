/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:13:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 11:53:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/setup.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

// rl_on_new_line : Regenerate the prompt on a newline
// rl_replace_line : Clear the previous text
void	handle_sigint(int sig)
{
	(void)sig;
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		if (g_mish.mode == M_INTRACTIVE)
		{
			write(STDOUT_FILENO, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_mish.exit_status = 130;
		}
		else
			write(STDOUT_FILENO, "\n", 1);
	}
}

void	exec_routine(char *input, t_data **data)
{
	t_ast	*ast;
	t_token	*token;

	if (!input)
		ft_exit(NULL, *data);
	else if (!*input)
		;
	else if (*input)
	{
		add_history(input);
		token = ft_get_tokens(input);
		if (token && !ft_grammar(token))
		{
			ast = ft_parse_ast(&token);
			if (ast)
			{
				*data = ft_setup_data(*data, ast);
				g_mish.exit_status = ft_executor(*data, ast);
				ft_waitpids((*data)->wpids);
				handel_cmd_end((*data));
			}
		}
		else
			ft_free_tokens(&token);
	}
}

char	*get_input(void)
{
	char	*input;
	char	*line;

	g_mish.mode = M_INTRACTIVE;
	if (isatty(STDIN_FILENO))
		input = readline(FT_NAME "$ ");
	else
	{
		line = get_next_line(STDIN_FILENO);
		input = ft_strtrim(line, "\n");
		if (line)
			free(line);
	}
	g_mish.mode = M_EXECUTION;
	return (input);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_data	*data;

	data = NULL;
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
		perror("signal");
	signal(SIGQUIT, SIG_IGN);
	ft_setup_mish(ac, av, env);
	while (1)
	{
		input = get_input();
		exec_routine(input, &data);
		free(input);
	}
	ft_handel_exit(data, g_mish.exit_status);
}
