/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 04:48:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 09:59:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

static t_type	_set_token(char **ptr, t_word **word);
static t_type	_redir_type(char **cmd);
static t_word	*_get_word(char **cmd);
static void		add_node(t_token **tmp, t_token **new_tk);

t_token	*ft_get_tokens(char *cmd)
{
	t_token	*tmp;
	t_token	*new_tk;
	t_token	*head;

	head = NULL;
	tmp = NULL;
	while (*cmd)
	{
		while (ft_isspace(*cmd))
			cmd++;
		if (!*cmd)
			break ;
		new_tk = ft_calloc(sizeof(t_token), 1);
		new_tk->type = _set_token(&cmd, &(new_tk->word));
		if (new_tk->type == T_UNKNOWN)
			return (ft_free_tokens(&head), NULL);
		if (!head)
		{
			head = new_tk;
			tmp = new_tk;
		}
		else
			add_node(&tmp, &new_tk);
	}
	return (head);
}

static void	add_node(t_token **tmp, t_token **new_tk)
{
	(*tmp)->next = *new_tk;
	(*new_tk)->prev = *tmp;
	*tmp = *new_tk;
}

static t_type	_set_token(char **ptr, t_word **word)
{
	if ((*ptr)[0] == '|' && (*ptr)[1] == '|' && (*ptr)++ && (*ptr)++)
		return (T_OR);
	if ((*ptr)[0] == '&' && (*ptr)[1] == '&' && (*ptr)++ && (*ptr)++)
		return (T_AND);
	if ((*ptr)[0] == '|' && (*ptr)++)
		return (T_PIPE);
	if ((*ptr)[0] == '(' && (*ptr)++)
		return (T_LPAR);
	if ((*ptr)[0] == ')' && (*ptr)++)
		return (T_RPAR);
	if (*(*ptr) == '<' || *(*ptr) == '>')
		return (_redir_type(ptr));
	*word = _get_word(ptr);
	if (!*word)
		return (T_UNKNOWN);
	return (T_WORD);
}

static t_word	*_get_word(char **cmd)
{
	t_word	*word;
	char	open;

	word = ft_calloc(sizeof(t_word), 1);
	if (!word)
		return (NULL);
	word->ptr = *cmd;
	open = 0;
	while (**cmd)
	{
		if (**cmd == '\'' || **cmd == '"')
		{
			if (!open || open == **cmd)
				open = **cmd * !(open == **cmd);
		}
		else if (**cmd == '&' && *((*cmd) + 1) != '&')
			;
		else if (!open && (ft_strchr(FT_DELIMS, **cmd) || ft_isspace(**cmd)))
			break ;
		++*cmd;
	}
	if (open)
		return (free(word), ft_pserror(NULL, ERR_SYNTAX, open), NULL);
	word->len = (size_t)(*cmd - word->ptr);
	return (word);
}

static t_type	_redir_type(char **cmd)
{
	if (**cmd == '<')
	{
		if (*(++*cmd) == '<' && ++*cmd)
			return (T_LLESS);
		return (T_LESS);
	}
	if (*(++*cmd) == '>' && ++*cmd)
		return (T_GGREAT);
	return (T_GREAT);
}
