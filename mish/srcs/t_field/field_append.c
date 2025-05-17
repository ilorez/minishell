/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 15:46:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

// append to string
// <null-terminated> not included in str->size
int	field_append(t_field *field, char c, int flag)
{
	if (!field)
		return (0);
	if (!str_append(field->str, c))
		return (0);
	if (!str_append(field->flags, flag))
		return (0);
	return (1);
}

int	field_append_list(t_field *field, char *l, int flag)
{
	if (!field)
		return (0);
	if (!str_append_list(field->str, l))
		return (0);
	if (!str_append_list(field->flags, ft_memset(l, flag, ft_strlen(l))))
		return (0);
	return (1);
}
