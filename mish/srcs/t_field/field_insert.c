/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:49 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 15:46:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

int	field_insert(t_field *field, size_t at, char *txt, int tag)
{
	if (!field || !txt)
		return (0);
	if (!str_insert(field->str, at, txt))
		return (0);
	if (!str_insert(field->flags, at, ft_memset(txt, tag, ft_strlen(txt))))
		return (0);
	return (1);
}
