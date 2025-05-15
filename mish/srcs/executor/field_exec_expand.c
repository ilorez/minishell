/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_exec_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:44:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 21:53:31 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

static void _get_env(t_field *r, char *word, int tag);

void field_expand(t_field *field)
{
  t_str *str;

  str = field->str;
  str->i = -1;
  while (++str->i < str->_wi)
  {
    if (str->value[str->i] == '\'')
    {
      field_drop_item(field, str->i);
      while (str->value[++str->i] != '\'')
        field_flags_set(field, str->i, '1');
      field_drop_item(field, str->i);
    }
    else if (str->value[str->i] == '\"')
    {
      field_drop_item(field, str->i);
      while (str->value[++str->i] != '\"')
      {
        if (str->value[str->i] == '$')
          _get_env(field, &(str->value[str->i]), '1'); 
        field_flags_set(field, str->i, '1');
      }
      field_drop_item(field, str->i);
    }
    else if (str->value[str->i] == '$')
        _get_env(field, &(str->value[str->i]), '0'); 
  }
}

static void _get_env(t_field *r, char *word, int tag)
{
  char *var;

  if (!ft_isalpha(*++word) && *word != '_')
  {
      r->str->i++;
      return;
  }
  var = ft_get_word(word);
  if (!var)
     return;
  field_drop_list(r, r->str->i, r->str->i + ft_strlen(var));
  field_insert(r, r->str->i, getenv(var), tag); 
  free(var);
}
