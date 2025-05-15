/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_drop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:54:10 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 20:59:01 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

int field_drop_item(t_field *field, size_t at_index)
{
  if (!field)
    return (0);
  if (!str_drop_item(field->str, at_index))
    return (0);
  if (!str_drop_item(field->flags, at_index))
    return (0);
  return (1);
}

int field_drop_list(t_field *field, size_t from, size_t to)
{
  if (!field || from >= to)
    return (0);
  if (!str_drop_list(field->str, from, to))
    return (0);
  if (!str_drop_list(field->flags, from, to))
    return (0);
  return (1);
}
