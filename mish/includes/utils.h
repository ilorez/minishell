/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:19:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 15:26:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./container.h"

// handel exit
void	ft_handel_exit(t_data *data, int status);
void	exit_err(char *msg, t_errno code);

// heredoc
t_redir	*ft_heredoc(char *eof);

// get word
char	*ft_get_word(char *str);

// wait macors
int		ft_wexitstatus(int status);
int		ft_wifexited(int status);

// free methods
void	ft_free_data(t_data *data);
void	ft_free_tokens(t_token **tks);

// command end
int		restore_std(int std, int flags, int status);
int		handel_cmd_end(t_data *data);

#endif
