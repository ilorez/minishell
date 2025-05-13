/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:09:51 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/13 20:47:30 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./container.h"
# include "./types.h"

// executor
int		ft_executor(t_data *data, t_ast *ast);

// exec_utils.c
char	*ft_get_right_path(char *cmd, char **paths);
int		ft_change_fd(int fd, int to, t_data *data);
int		ft_waitpids(t_arr *pid);
int		ft_killpids(t_arr *pid);
int		_is_match(t_arr *wild, char *name);

// wait macors
int		ft_wexitstatus(int status);
int		ft_wifexited(int status);

#endif // !EXECUTOR_H
