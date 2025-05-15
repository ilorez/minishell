/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:09:51 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 23:07:25 by znajdaou         ###   ########.fr       */
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

// expansion
char **ft_extract(char **argv);

// field exec expand 
void field_expand(t_field *field);
t_arr *field_split(t_field *field, int tag, int (f)(int));

//t_arr *ft_word_expansion(char *word);

// wild match
t_arr *ft_wild_match(t_arr *wild);

// expansion var
//char **ft_expan_vars(char **word);

#endif 
