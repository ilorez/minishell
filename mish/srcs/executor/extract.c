/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 12:42:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

// flags
// 1: normal
// 2: inside quotes
// 3: inside single quotes
//
t_arr *_fields_expand(t_arr *fields);

char **ft_extract(char **argv)
{
  int i;
  t_arr *args;
  t_arr *tmp;

  args = NULL;
  i = -1;
  while (argv[++i])
  {
    tmp = ft_extract_arg(argv[i]);
    if (!tmp)
      return (arr_free(args), NULL);
    args = arr_merge(args, tmp);
  }
  return ((char **)arr_extract(&args));
}

t_arr *ft_extract_arg(char *arg)
{
  t_field *field;
  t_arr *fields;
  t_arr *wilds;
  t_arr *args;
  char *tmp;

  args = arr_new();
  field = field_new(arg, '0');
  if (!field)
    return (NULL);
  field_expand(field); // expand vars
  fields = field_split(field, '0', ft_isspace); // split by spaces
  //field_clean(&field);
  fields->i = -1;
  while (++(fields->i) < fields->index)
  {
    tmp = field_extract_copy(fields->content[fields->i]);
    wilds = field_split_char(fields->content[fields->i], '0', '*'); // split by *
    if (wilds->index > 1)
    {
      wilds = _fields_expand(wilds); // from arr of fields to arr of str
      wilds = ft_wild_match(wilds);
      if (wilds->index)
      {
        args = arr_merge(args, wilds);// merge arr will free wilds
        free(tmp);
        continue;
      }
    }
    arr_free(wilds);
    // and :D you are about to get yourself in sigma line ! :>/ 
    arr_append(args, tmp);
  }
  arr_free_body(fields);
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

