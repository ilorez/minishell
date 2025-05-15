/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:10:47 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 22:16:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_str *str_split_at(t_str *str, size_t at_index)
{
  t_str *second;

  if (!str || str->_wi <= at_index)
    return (NULL);
  second = str_new(&(str->value[at_index]));
  str->_wi = at_index;
  str->value[at_index] = 0;
  str->i = 0;
  return (second);
}
