/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:08:01 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 21:50:43 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

int field_flags_set(t_field *field, size_t at_index, int c)
{
  if (!field)
    return (0);
  if (!str_set(field->flags, at_index, c))
    return (0);
  return (1);
}
