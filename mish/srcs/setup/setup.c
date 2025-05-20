/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:27:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 00:02:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

// TODO:
//  - ENVIR: [x] tested
//      - [x] ft_getenv
//      - [x] ft_setenv
//      - [x] ft_getpaths
//      - [x] ft_unsetenv
//
//  - free [x] tested
//      - [x] ft_free_all (data, mish)
//
//  - buildins [x] tested
//      - [x] finish cd echo env exit pwd unset
//      - [x] export buildin
//
//  - executor [ ] tested
//      - [x] update mish.exit_status
//      - [x] link get_paths
//      - [x] link $?
//      - [x] link buildins
//      - [x] memory leeks
//      - [ ] norminette
//
//  - Signals [ ] tested
//      - [ ] signal kill (killpids)
//  - link
//      - [ ] link with parser
//      - [ ] test
//      - [ ] push

t_mish			g_mish;

static t_arr	*_create_lenv(char **envp)
{
	int		i;
	t_arr	*lst_env;

	lst_env = arr_new();
	if (!lst_env)
		return (NULL);
	i = -1;
	while (envp && envp[++i])
		arr_append(lst_env, ft_strdup(envp[i]));
	ft_setenv("PWD", g_mish.cwd, 1);
	return (lst_env);
}

t_data	*ft_setup_data(t_ast *ast)
{
	t_data	*data;

	if (!ast)
		return (NULL);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->wpids = arr_new();
	if (!data->wpids)
		return (free(data), NULL);
	data->fd[0] = STDIN_FILENO;
	data->fd[1] = STDOUT_FILENO;
	data->ast = ast;
	return (data);
}

int	ft_setup_mish(int ac, char **av, char **envp)
{
	(void)ac, (void)av;
	g_mish.exit_status = 0;
	if (!getcwd(g_mish.cwd, PATH_MAX))
		return (0);
	g_mish.envp = _create_lenv(envp);
	if (!g_mish.envp)
		return (0);
	return (1);
}
