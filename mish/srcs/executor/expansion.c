/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/11 10:56:17 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <stdlib.h>

static void _double_quote(t_str *r, char **word);
static void _get_env(t_str *r, char **word);
static char *_get_word(char **str);

// todo:
//    - find where word for $word stop delimiters
//    - think about it, should i use other char like numbers and symbols that i'm not using it in minishell as normal chars or try to make same result
//    - ofcourse use it as simple chars
//    - becouse i should stay in subject requirement
//    - complete this
//    
char *ft_word_expansion(char *word)
{
  t_str *r;
  t_arr *wild;
  char *start;


  r = str_new_empty(6);
  wild = arr_new();
  start = r->value;
  if (!word)
    return ft_strdup("");
  while (*word)
  {
    if (*word == '\'')
    {
      while (*++word != '\'')
        str_append(r, *word);
      word++;
    }
    else if (*word == '"')
      _double_quote(r, &word);
    else if (*word == '$')
      _get_env(r, &word);
    else if (*word == '*')
    {
      arr_append(wild, ft_strdup(start));
      str_append(r, *word++);
      start = &(r->value[r->_wi]);
    }
    continue;
    if (*word)
      str_append(r, *word++);
  }
  if (wild->index)
  {
      arr_append(wild, ft_strdup(start));
      // TODO: print wild for test
  }
  return str_extract(&r);
}

static void _double_quote(t_str *r, char **word)
{
  while (*(++*word) != '"')
  {
    if (**word == '$')
    {
      if (ft_isspace(*(++*word)))
        str_append(r, '$');
      else 
        _get_env(r, word);
    }
    continue;
    str_append(r, **word);
  }
  ++*word;
}

static char *_get_word(char **str)
{
  int i;
  char *word;
  char *tmp;

  i = 0;
  word = NULL;
  if (!str || *str)
    return (NULL);
  tmp = *str;
  if (!ft_isalpha(*tmp) && *tmp != '_')
    return (++*str, NULL);
  while (*++tmp && (!ft_isspace(*tmp) || ft_isalnum(*tmp) || *tmp == '_'))
    i++;
  if (!i)
    return (NULL);
  word = ft_calloc(i+1, sizeof(char));
  if (!word)
    return NULL;
  ft_strlcpy(word, *str, i);
  *str = tmp;
  return (word);
}

static void _get_env(t_str *r, char **word)
{
  char *var;

  var = _get_word(word);
  if (!var)
     return;
  str_append_list(r, getenv(var)); 
  free(var);
}

// --- Main ---
int main(void) {
	char *tests[] = {
		"hello",
		"'no expand'",
		"\"$USER home\"",
		"$HOME/dir",
		"\"$HOME/$USER\"",
		"foo*bar",
		NULL
	};

	for (int i = 0; tests[i]; i++) {
		char *expanded = ft_word_expansion(tests[i]);
		printf("Input:    %s\n", tests[i]);
		printf("Expanded: %s\n", expanded);
		free(expanded);
		puts("------");
	}
	return 0;
}
