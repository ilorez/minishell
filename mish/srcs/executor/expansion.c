/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/12 00:16:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <stdlib.h>

static void _double_quote(t_str *r, char **word);
static void _get_env(t_str *r, char **word);
static char *_get_word(char **str);

// TODO:
//  - more tests
//  - ask your teamate about it's opinion in the logic
//  - norminete

void arr_print_str(t_arr *arr);
char *ft_word_expansion(char *word)
{
  t_str *r;
  t_arr *wild;
  size_t start;


  r = str_new_empty(6);
  wild = arr_new();
  start = 0;
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
      // TODO: print wild for test
      arr_print_str(wild);
  }
  return str_extract(&r);
}

void arr_print_str(t_arr *arr)
{
	if (!arr || !arr->content)
		return;

	for (int i = 0; i < arr->index; i++)
	{
		char *str = (char *)arr->content[i];
		if (str)
			printf("[%d]: %s\n", i, str);
		else
			printf("[%d]: (null)\n", i);
	}
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
  while ((ft_isalnum(*tmp) || *tmp == '_') && *++tmp)
    i++;
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

// --- Main ---
int main(void) {
	char *tests[] = {
		"hello",
		"'no expand'",
		"\"$USER home\"",
		"$HOME/dir",
		"\"$HOME/$USER\"",
		"foo*bar",
		"****foo****bar****",
		"\"$1SER home\"",
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
