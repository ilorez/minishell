/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:19:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/23 09:45:06 by znajdaou         ###   ########.fr       */
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
int	ft_wcoredump(int status);

// free methods
void	ft_free_data(t_data **data);
void	ft_free_tokens(t_token **tks);
void	ft_free_all(t_data **data);

// command end
int		ft_restore_std(int std, int flags, int status);
int		handel_cmd_end(t_data *data);

// helpers
char	*ft_getenv(const char *name);
char	**ft_getpaths(void);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_unsetenv(const char *name);

// signals
int ft_check_status(int status);

#endif
