/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:25:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 19:34:54 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// str clean
char	*str_extract(t_str **str)
{
	char	*tmp;

	if (!str || !*str)
		return (NULL);
	tmp = (*str)->value;
	free(*str);
	*str = NULL;
	return (tmp);
}

size_t str_len(t_str *str)
{
  if (!str)
    return (0);
  return (str->_wi);
}
