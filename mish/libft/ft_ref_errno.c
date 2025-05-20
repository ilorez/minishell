/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ref_errno.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:51:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/19 16:35:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/t_errno.h"
#include <unistd.h>

void	ft_ref_perror(char *subref, char *msg, t_errno error_code)
{
	ft_putstr_fd(FT_EXEC_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(subref, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_perror(msg, error_code);
}
