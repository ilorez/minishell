/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:19:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 19:59:48 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./container.h"

void	ft_handel_exit(t_data *data, int status);
void	ft_free_tokens(t_token **tks);
t_redir	*ft_heredoc(char *eof);
void	exit_err(char *msg, t_errno code);


// get word 
char *ft_get_word(char **str);

// wait macors
int		ft_wexitstatus(int status);
int		ft_wifexited(int status);



#endif
