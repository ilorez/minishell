/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:49 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/17 13:42:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

int	field_insert(t_field *field, size_t at, char *txt, int tag)
{
  char *tmp;

	if (!field || !txt)
		return (0);
	if (!str_insert(field->str, at, txt))
		return (0);
  tmp = ft_strdup(txt);
	if (!str_insert(field->flags, at, ft_memset(tmp, tag, ft_strlen(txt))))
		return (free(tmp), 0);
  free(tmp);
	return (1);
}
