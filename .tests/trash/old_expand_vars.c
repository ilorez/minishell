/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:33:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 11:56:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <stdio.h>


static t_arr *_expan_var(char *word);
static void _get_env(t_str *r, char **word);
static void _double_quote(t_str *r, char **word);

char **ft_expan_vars(char **word)
{
  t_arr *all;
  char *str_tmp;
  t_arr *arr_tmp;


  all = arr_new();
  if (!all)
    return (NULL);
  while (*word)
  {
    arr_tmp = _expan_var(*word++);
    if (!arr_tmp)
      return (arr_free(all), NULL);
    arr_merge(all, arr_tmp);
  }
  return ((char **)arr_extract(&all));
}

static t_arr *_expan_var(char *word)
{
  t_arr *result;
  t_str *r;
  char *tmp;
  char *tmp2;
  char **spl;

  while (*word)
  {
    if (*word == '\'')
      while (*word++ != '\'')
        str_append(r, *word);
    else if (*word == '"')
      _double_quote(r, &word);
    else if (*word == '$')
    {
      if (!ft_isalpha(*++word) && *word != '_')
        str_append(r, '$');
      else 
      {
        tmp2 = ft_get_word(&word);
        if (tmp2)
          ;// todo
        tmp = getenv(tmp2);
        free(tmp2);
        spl = ft_split_cond(tmp, ft_isspace);
        if (!spl)
          ;//todo
        if (!ft_isspace(*tmp))
          str_append_list(r, *spl++);
        arr_append(result, r);
        if (*spl)
          str_empty(r);
        while (*spl && *(spl+1))
          arr_append(result, ft_strdup(*spl++));
        if (*spl)
          str_append_list(r, *spl);
      }
    }
    else
      str_append(r, *word++);
  }
  return (result);
}

static void _double_quote(t_str *r, char **word)
{
  str_append(r, *(*word)++);
  while (*((*word)++) != '"')
  {
    if (**word == '$')
    {
      _get_env(r, word);
      --*word; // because we are increment in loop condition
      continue;
    }
    str_append(r, **word);
  }
}

static void _get_env(t_str *r, char **word)
{
  char *var;

  if (!ft_isalpha(*++*word) && **word != '_')
  {
      str_append(r, '$');
      return;
  }
  var = ft_get_word(word);
  if (!var)
     return;
  str_append_list(r, getenv(var)); 
  free(var);
}
