/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:36:39 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 19:47:00 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// create empty string
int str_insert(t_str *str, size_t at, char *text)
{
  char *tmp;

  if (!str || !text || !*text || str->_wi < at)
    return (0);
  tmp = ft_strdup(&str->value[at]);
  if (!tmp)
    return (0);
  str->_wi = at;
  str_append_list(str, text);
  str_append_list(str, tmp);
  free(tmp);
  return (1);
}


