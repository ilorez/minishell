/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:51:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/16 17:02:16 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/t_errno.h"

static void	_ft_create_err_list(char *lst[ERR_COUNT])
{
	char	*err_msgs[ERR_COUNT];

	err_msgs[ERR_SUCCESS] = "OK\n";
	err_msgs[ERR_INVALID_ARG] = "invalid argument\n";
	err_msgs[ERR_EMPTY_ARG] = "Empty argumnet\n";
	err_msgs[ERR_MALLOC_FAIL] = "an allocation failed\n";
	err_msgs[ERR_UNKNOWN] = "Unknown error occurred\n";
	ft_memcpy(lst, err_msgs, sizeof(char *) * ERR_COUNT);
}

void	ft_strerr(t_errno error_code)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
}

void	ft_perror(char *msg, t_errno error_code)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	if (!msg || !*msg)
		ft_putstr_fd("Error", STDERR_FILENO);
	else
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
}
