/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_split_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:10:47 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 22:39:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

t_field *field_split_at(t_field *field, size_t at_index)
{
  t_field *second;
  t_field *tmp;

  if (!field)
    return (NULL);
  second = ft_calloc(1, sizeof(t_field));
  second->str = str_split_at(field->str, at_index); 
  second->flags = str_split_at(field->flags, at_index); 
  tmp = second;
  second = field;
  field = tmp;
  return (second);
}
