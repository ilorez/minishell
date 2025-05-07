/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 04:48:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/07 13:07:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

static t_type	_set_token(char **ptr, t_word **word);
static t_type	_redir_type(char **cmd);
static t_word	*_get_word(char **cmd);

t_token	*ft_get_tokens(char *cmd)
{
	t_token	*tk;
	t_token	*tmp;

	tk = ft_calloc(sizeof(t_token), 1);
	tmp = tk;
	while (*cmd)
	{
		while (ft_isspace(*cmd))
			cmd++;
		if (!*cmd)
			break ;
		tk->next = ft_calloc(sizeof(t_token), 1);
		tk = tk->next;
		if (!tk)
			return (tmp);
		tk->type = _set_token(&cmd, &(tk->word));
		if (tk->type == T_UNKNOW)
			return (ft_free_tokens(&tmp), NULL);
	}
	return (tmp);
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
		return (T_UNKNOW);
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
		if (**cmd == '"' || **cmd == '\'')
        open = (**cmd) * (open == **cmd);
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
