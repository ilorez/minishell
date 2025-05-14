/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/13 23:50:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <stdio.h>
#include <stdlib.h>

static void _double_quote(t_str *r, char **word);
static void _get_env(t_str *r, char **word);
static char *_get_word(char **str);

// TODO:
//  - more tests
//  - norminete
char **ft_extract(char **argv)
{
  t_arr *tmp;
  t_arr *all;

  if (!argv || !*argv)
    return (NULL);
  all = ft_calloc(sizeof(t_arr), 1);
  if (!all)
    return (NULL);
  all = arr_new();
  while (*argv)
  {
    tmp = ft_word_expansion(*argv++);
    if (!tmp)
      return (arr_free(all), NULL); 
    if (!arr_merge(all, tmp))
      return (arr_free(all), NULL);
  }
  return ((char **)arr_extract(&all));
}

t_arr *ft_word_expansion(char *word)
{
  t_str *r;
  t_arr *wild;
  size_t start;

  r = str_new_empty(6);
  if (!r)
    return NULL;
  wild = arr_new();
  if (!wild)
    return (str_clean(&r), NULL);
  start = 0;
  while (*word)
  {
    if (*word == '\'')
      while (*++word != '\'' || (word++ && 0))
        str_append(r, *word);
    else if (*word == '"')
      _double_quote(r, &word);
    else if (*word == '$')
      _get_env(r, &word);
    else if (*word == '*')
    {
      if (start != r->_wi || !r->_wi) // so it's will count the serie of wilds as one wild
        arr_append(wild, ft_strdup(&(r->value[start])));
      str_append(r, *word++);
      start = r->_wi;
    }
    else
      str_append(r, *word++);
  }
  if (wild->index)
  {
      arr_append(wild, ft_strdup(&(r->value[start])));
      // get match files
      wild = ft_wild_match(wild);
      if (wild->index)
        return (str_clean(&r), wild);
  }
  arr_append(wild, str_extract(&r));
  return (wild);
}

static void _double_quote(t_str *r, char **word)
{
  while (*(++*word) != '"')
  {
    if (**word == '$')
    {
      _get_env(r, word);
      --*word; // because we are increment in loop condition
      continue;
    }
    str_append(r, **word);
  }
  ++*word;
}

static char *_get_word(char **str)
{
  int i;
  char *word;
  char *tmp;

  i = 1;
  word = NULL;
  if (!str || !*str)
    return (NULL);
  tmp = *str;
  while ((ft_isalnum(*tmp) || *tmp == '_') && ++i)
    tmp++;
  word = ft_calloc(i, sizeof(char));
  if (!word)
    return NULL;
  ft_strlcpy(word, *str, i);
  *str = tmp;
  return (word);
}

static void _get_env(t_str *r, char **word)
{
  char *var;

  if (!ft_isalpha(*++*word) && **word != '_')
  {
      str_append(r, '$');
      return;
  }
  var = _get_word(word);
  if (!var)
     return;
  str_append_list(r, getenv(var)); 
  free(var);
}
/*
// --- Main ---
int main(void) {
  char **expanded;
	//	"hello",
	//	"'no expand'",
	//	"\"$USER home\"",
	//	"$HOME/dir",
	//	"\"$HOME/$USER\"",

	char *tests[] = {
		"foo*bar",
	//	"****foo****bar****",
	//	"\"$1SER home\"",
		NULL
	};

  for (int i = 0; tests[i]; i++) {
		printf("[%d]-%s\n", i, tests[i]);
	}
  puts("---------------------------");
	expanded = ft_extract(tests);
  if (!expanded)
    return (ft_perror(NULL, ERR_MALLOC_FAIL), 1);
	for (int i = 0; expanded[i]; i++) {
		printf("- %s\n", expanded[i]);
	}
	ft_free_str_lst(expanded);
	return 0;
}*/
