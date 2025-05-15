/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 18:37:17 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <stdio.h>
#include <stdlib.h>

// flags
// 1: normal
// 2: inside quotes
// 3: inside single quotes
t_field *ft_extract_arg(char *arg)
{
  t_field *field;
  t_arr *fields;
  t_arr *args;

  field = field_new(arg, 0);
  field_expand(field); // expand vars
  fields = field_split(field, 0, ft_isspace);
  while (item in fields);
  {
    // wilds = filed_split(field, 0, ft_iswild());
    // if wilds->index > 1
    // {
    //  wilds = ft_wild_match(wilds);
    //  if (wild->index)
    //    append wilds t0 args
    //    continue;
    //  }
    // else
    //  append item to args
  }




  return (field);
}



