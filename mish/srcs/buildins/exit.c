/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:40:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/29 16:25:17 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"
#include <unistd.h>

// exit
//  - free all data and exit
//  - it's ignore opetion but not argument
void	ft_exit(char **argv, t_data *data)
{
	int	status;

	if (!argv || !*argv)
		status = g_mish.exit_status;
	else if (!ft_is_valid_num(*argv))
	{
		status = 2;
		ft_ref_perror("exit", *argv, ERR_NONUM);
	}
	else if (*(argv + 1))
	{
		g_mish.exit_status = 1;
		return (ft_ref_perror("exit", NULL, ERR_TO_MANY_ARG));
	}
	else
		status = atoi(*argv);
	if (data)
		ft_waitpids(data->wpids);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "exit\n", 5);
	ft_handel_exit(data, status);
}
