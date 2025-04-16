/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:55:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/16 17:59:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./read_test.h"

// expand string
void ft_string_expand(t_string *str, size_t size)
{
  char *tmp;
  if (!str)
    return ;
  tmp = ft_calloc(size + str->size + 1, 1);
  if (!tmp)
    return ;
  ft_strlcpy(tmp, str->value, str->size + size + 1);
  free(str->value);
  str->value = tmp;
}

// append to string
void ft_string_append(t_string *str, char c)
{
  if (!str)
    return;
  if (str->size - str->used == 0)
    ft_string_expand(str, 10);
  str->value[str->index++] = c;
  str->value[str->index] = 0;
  str->used++;
}

// create string
t_string *ft_create_empty_str(size_t size)
{
  t_string *str;

  str = ft_calloc(sizeof(t_string), 1);
  if (!str)
    return (NULL);
  str->value = ft_calloc(size + 1, 1);
  if (!str->value)
    return (free(str), NULL);
  str->size = size;
  str->value[0] = 0;
  return (str);
}
