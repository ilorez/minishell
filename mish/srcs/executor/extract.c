/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 23:52:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

int ft_iswild(int c)
{
  if (c == '*')
    return (1);
  return (0);
}
// flags
// 1: normal
// 2: inside quotes
// 3: inside single quotes
//
t_arr *_fields_expand(t_arr *fields);
t_arr *ft_extract_arg(char *arg)
{
  t_field *field;
  t_arr *fields;
  t_arr *wilds;
  t_arr *args;

  field = field_new(arg, '0');
  if (!field)
    return (NULL);
  field_expand(field); // expand vars
  fields = field_split(field, '0', ft_isspace); // split by spaces
  field_clean(&field);
  fields->i = -1;
  while (++(fields->i) < fields->index)
  {
    wilds = field_split(fields->content[fields->i], '0', ft_iswild); // split by *
    if (wilds->index > 1)
    {
      wilds = _fields_expand(wilds);
      wilds = ft_wild_match(wilds);
      if (wilds->index)
      {
        arr_merge(args, wilds);
        continue;
      }
      else
        arr_free(wilds);
    }
    // TODO: should we really free like that ??
    // TODO: because it's extract and when run arr_free fields button it's be already freed and that will cause an error
    // TODO: also for wilds make clear free
    // and :D you are about to get yourself in sigma line ! :>/ 
    arr_append(args, field_extract((t_field **)(&(fields->content[fields->i]))));
  }
  arr_free(fields);
  return (args);
}

t_arr *_fields_expand(t_arr *fields)
{
  fields->i = -1;
  while (++fields->i < fields->index)
    fields->content[fields->i] = field_extract((t_field **)(&(fields->content[fields->i])));
  fields->clean = free;
  return fields;
}

