/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:05:53 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/08 17:15:01 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		ft_grammar(t_token *lst);
t_ast	*ft_parse_ast(t_token **lst);
t_ast	*parse_or(t_token **lst);
t_ast	*parse_and(t_token **lst);
t_ast	*parse_pipe(t_token **lst);
t_ast	*parse_redir(t_token **lst);
t_ast	*parse_word(t_token **lst);
t_ast	*parse_list(t_token **lst);

#endif
