/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:02:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 21:06:06 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int str_set(t_str *str, size_t at_index, int c)
{
  if (!str || str->_wi <= at_index)
    return (0);
  str->value[at_index] = c;
  return (1);
}
