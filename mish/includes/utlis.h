/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:19:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/09 11:25:03 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./container.h"

void	ft_free_tokens(t_token **tks);
t_redir	*ft_heredoc(char *eof);
void	exit_err(char *msg, t_errno code);

#endif
