/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:19:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/23 11:38:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <signal.h>
#include <sys/wait.h>

/* this fucntion return 1 or 0
 * first it check if that is a normal termination
 *    - true
 *        [get exit status and update g_mish.exit_status]
 *        return (1)
 *    - flase
 *        [check if that signal is SIGINT] => set g_mish.exit_status = 130;
 *        [check core dump] => print core dumped
 *        return (0)
 *
 */

// return 1 in case of normal exit otherwise 0
int	ft_check_status(int status)
{
	int	r;

	if (ft_wifexited(status))
	{
		g_mish.exit_status = ft_wexitstatus(status);
		return (1);
	}
	else if (WIFSIGNALED(status))
	{
		r = WTERMSIG(status);
		if (r == SIGINT)
			g_mish.exit_status = 130;
		else if (r == SIGQUIT)
			g_mish.exit_status = 131;	
	}
	return (0);
}
