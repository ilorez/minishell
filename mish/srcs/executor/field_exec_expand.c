/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_exec_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:44:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/19 16:03:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

static void	_get_env(t_field *r, char *word, int tag);
static void	_double_quotes(t_field *field, t_str *str);

void	field_expand(t_field *field)
{
	t_str	*str;

	str = field->str;
	str->i = 0;
	while (str->i < str->_wi)
	{
		if (str->value[str->i] == '\'')
		{
			field_drop_item(field, str->i);
			while (str->value[str->i] != '\'')
				field_flags_set(field, str->i++, '1');
			field_drop_item(field, str->i);
		}
		else if (str->value[str->i] == '\"')
			_double_quotes(field, str);
		else if (str->value[str->i] == '$')
			_get_env(field, &(str->value[str->i]), '0');
		else
			str->i++;
	}
}

static void	_double_quotes(t_field *field, t_str *str)
{
	field_drop_item(field, str->i);
	while (str->value[str->i] != '\"')
	{
		if (str->value[str->i] == '$')
			_get_env(field, &(str->value[str->i]), '1');
		else
			field_flags_set(field, str->i++, '1');
	}
	field_drop_item(field, str->i);
}

// Note "+1" at this function is for $
static void	_get_env(t_field *r, char *word, int tag)
{
	char	*var;
	char	*env;

	if (!ft_isalpha(*++word) && *word != '_')
	{
    if (*word == '?')
    {
	    field_drop_list(r, r->str->i, r->str->i + 2);
	    field_insert(r, r->str->i++, ft_itoa(mish.exit_status), tag);
    }
    else
		  r->str->i++;
		return ;
	}
	var = ft_get_word(word);
	if (!var)
	{
		r->str->i++;
		return (ft_perror(NULL, ERR_MALLOC_FAIL));
	}
	field_drop_list(r, r->str->i, r->str->i + 1 + ft_strlen(var));
	env = getenv(var);
	free(var);
	field_insert(r, r->str->i, env, tag);
	r->str->i += ft_strlen(env);
}
