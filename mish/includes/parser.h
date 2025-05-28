/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:05:53 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/16 14:22:10 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		ft_grammar(t_token *lst);
int ft_operators(t_token **lst);
int ft_parenthese(t_token **lst);
int ft_command(t_token **lst);
t_ast	*ft_parse_ast(t_token **lst);
t_ast	*parse_or_and(t_token **lst);
t_ast	*parse_pipe(t_token **lst);
t_ast	*parse_redir(t_token **lst);
t_ast	*parse_word(t_token **lst);
t_ast	*parse_list(t_token **lst);
void	next_token(t_token **lst);
int		match(t_token **lst, t_type tt);
t_ast	*new_node(t_type tt, void *value, t_ast *r, t_ast *l);
t_redir		*fill_redir(t_token **lst);
int	match_op(t_token **lst, int is_redir);
t_ast	*consume_redir(t_token **lst);
t_ast	*add_back_node(t_ast *lst, t_ast *end);
void	consume_node(t_token *lst);

#endif
