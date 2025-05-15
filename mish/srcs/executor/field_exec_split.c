/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_exec_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:44:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 22:07:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

void field_split(t_field *field, int tag, int (f)(int))
{
  t_str *str;
  t_arr *arr;

  arr = arr_new();
  str = field->str;
  str->i = -1;
  while (++str->i < str->_wi)
  {
    if (field->flags->value[str->i] == '0' && f(str->value[str->i]))
    {
    }
  }
}

