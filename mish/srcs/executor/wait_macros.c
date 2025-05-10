/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_macros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 02:37:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/09 02:42:35 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* wifexited, applique WIFEXITED macro behavior
 * Check if the child process exited normally
 * If the lower 7 bits are zero, the process exited normally
 * */
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
