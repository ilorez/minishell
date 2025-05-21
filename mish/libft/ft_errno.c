/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:51:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/20 19:36:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/t_errno.h"
#include <unistd.h>

static void	_ft_create_err_list(char *lst[ERR_COUNT])
{
	char	*err_msgs[ERR_COUNT];

	err_msgs[ERR_SUCCESS] = "OK";
	err_msgs[ERR_INVALID_ARG] = "invalid argument";
	err_msgs[ERR_EMPTY_ARG] = "Empty argumnet";
	err_msgs[ERR_EARGS] = "not enough arguments";
	err_msgs[ERR_CMDNF] = "command not found";
	err_msgs[ERR_NONUM] = "numeric argument required";
	err_msgs[ERR_IDENT] = "not a valid identifier";
	err_msgs[ERR_TO_MANY_ARG] = "too many arguments";
	err_msgs[ERR_ENOENT] = "No such file or directory";
	err_msgs[ERR_MALLOC_FAIL] = "an allocation failed";
	err_msgs[ERR_SYNTAX] = "syntax error";
	err_msgs[ERR_AMB_REDIR] = "ambiguous redirect";
	err_msgs[ERR_UNKNOWN] = "Unknown error occurred";
	ft_memcpy(lst, err_msgs, sizeof(char *) * ERR_COUNT);
}

void	ft_strerr(t_errno error_code)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}

void	ft_perror(char *msg, t_errno error_code)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	if (msg)
	{
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}

void	ft_serror(t_errno error_code, char *msg)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
	if (msg && *msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}

void	ft_pserror(char *prefix, t_errno error_code, char suffix)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	if (!prefix || !*prefix)
		ft_putstr_fd("Error", STDERR_FILENO);
	else
		ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
	if (suffix)
	{
		write(STDERR_FILENO, " ", 1);
		write(STDERR_FILENO, &suffix, 1);
	}
	write(STDERR_FILENO, "\n", 1);
}
