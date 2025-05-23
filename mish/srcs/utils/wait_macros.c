/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_macros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 02:37:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/23 09:32:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* wifexited, applique WIFEXITED macro behavior
 * Check if the child process exited normally
 * If the lower 7 bits are zero, the process exited normally
 * */
#include <sys/wait.h>
int	ft_wifexited(int status)
{
	return ((status & 0x7F) == 0);
}

/* wexitstatus, applique WEXITSTATUS macro behavior
 * Get the exit status of the child process
 * The exit status is stored in the upper byte
 * Note: we use here the & 0xFF for cut only the first 8 bits
 * if we didnt add it that will cause a probleme if we have higher bits seted.
 * return : -1 on error
 * */
int	ft_wexitstatus(int status)
{
	if (ft_wifexited(status))
	{
		return ((status >> 8) & 0xFF);
	}
	return (-1);
}

/* wcoredump, applique  WCOREDUMP macro behavior
 * the macro WCOREDUMP(status) return true 
 * if the child process produced a core dump file
 * the value stored in bit 7 in most signficant byte
 * Note: we use here the & 0x1 for cut only the first 1 bit
 * if we didnt add it that will cause a probleme if we have higher bits seted.
 * */
int	ft_wcoredump(int status)
{
  if (WIFSIGNALED(status))
	  return ((status >> 7) & 0x1);
  return (0);
}

