/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errno.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:44:36 by znajdaou          #+#    #+#             */
/*   Updated: 2025/06/01 19:00:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ERRNO_H
# define T_ERRNO_H

// errno representative
typedef enum s_errno
{
	ERR_SUCCESS = 0,
	ERR_INVALID_ARG,
	ERR_EMPTY_ARG,
	ERR_EARGS,
	ERR_CMDNF,
	ERR_NONUM,
	ERR_IDENT,
	ERR_RPATH,
	ERR_ISDIR,
	ERR_TO_MANY_ARG,
	ERR_ENOENT,
	ERR_MALLOC_FAIL,
	ERR_SYNTAX,
	ERR_AMB_REDIR,
	ERR_UNKNOWN,
	ERR_COUNT
}		t_errno;

// Errno function
void	ft_perror(char *msg, t_errno errno_num);
void	ft_strerr(t_errno errno_num);
void	ft_pserror(char *prefix, t_errno error_code, char suffix);
void	ft_serror(t_errno error_code, char *msg);

// refirence errno
void	ft_ref_perror(char *subref, char *msg, t_errno error_code);

#endif
