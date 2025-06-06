/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:09:51 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 18:58:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./container.h"
# include "./t_field.h"
# include "./types.h"

// executor
int		ft_executor(t_data *data, t_ast *ast);

// redir
int		ft_redir(t_data *data, t_ast *ast, t_redir *r);

// exec child
void	ft_exec_child(t_data *data, t_ast *ast);

// exec_utils.c
char	*ft_get_right_path(t_data *data, char *cmd);
int		ft_change_fd(int fd, int to, t_data *data);
int		ft_waitpids(t_arr *pid);
int		ft_dup2(int fd, int to, t_data *data);

// extract
char	**ft_extract(char **argv);
t_arr	*ft_extract_arg(char *arg);

// field exec expand
void	field_expand(t_field *field);
t_arr	*field_split(t_field *field, int tag, int (f)(int));
t_arr	*field_split_char(t_field *field, int tag, int c);

// wild match
t_arr	*ft_wild_match(t_arr *wild);

#endif
