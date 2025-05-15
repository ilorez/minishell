/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:51:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 11:07:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

// get the word from *str to not (alphanum) or _ char
char *ft_get_word(char **str)
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


