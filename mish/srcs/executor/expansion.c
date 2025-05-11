/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/11 03:37:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

void _double_quote(t_str *r, char **word);
char *ft_word_expansion(char *word)
{
  t_str *r;
  r = str_new_empty(6);

  if (!word)
    return ft_strdup("");
  while (*word)
  {
    if (*word == '\'')
      while (*++word != '\'')
        str_append(r, *word);
    if (*word == '"')
      _double_quote(r, &word);
    if (*word == '$')
      ;// str_append_list(r, get_env(get_word(word))); 
    if (*word == '*')
      ;// TODO: wildcard logic (no idea :V)
    if (*word)
      str_append(r, *word);
  }
  return str_extract(&r);
}

void _double_quote(t_str *r, char **word)
{
  char *var;

  while (*(++*word) != '"')
  {
    if (**word == '$')
    {
      if (ft_isspace(*(++*word)))
        str_append(r, '$');
      else 
      {
        //var = ft_get_word(word);
        // if (!var)
        //    continue;
        // str_append_list(r, get_env_var(var)); 
        // free(var);
      }
    }


      


  }
}
