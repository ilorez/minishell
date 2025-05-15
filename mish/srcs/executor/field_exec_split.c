/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_exec_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:44:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 23:45:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

// split field into parts
//      - go in all chars have <tag>
//      - run the condition function <f()> 
//        - on true split function
t_arr *field_split(t_field *field, int tag, int (f)(int))
{
  t_str *str;
  t_arr *arr;

  arr = arr_new();
  str = field->str;
  str->i = 0;
  while (str->i < str->_wi)
  {
    while (field->flags->value[str->i] == tag && f(str->value[str->i]))
      field_drop_item(field, str->i);
    while (str->value[str->i] && 
      (field->flags->value[str->i] != tag && !f(str->value[str->i])))
      str->i++;
    if (str->i != 0 && str->i != str->_wi)
      arr_append(arr, field_split_at(field, str->i));
  }
  arr_append(arr, field);
  arr->clean = field_free;
  return (arr);
}

