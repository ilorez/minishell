/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:52 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 15:46:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

t_field	*field_new_empty(size_t size)
{
	t_field	*field;

	field = ft_calloc(1, sizeof(t_field));
	if (!field)
		return (NULL);
	field->str = str_new_empty(size);
	field->flags = str_new_empty(size);
	return (field);
}

t_field	*field_new(char *content, int flag)
{
	t_field	*field;
	char	*tmp;

	tmp = ft_strdup(content);
	field = ft_calloc(1, sizeof(t_field));
	if (!field)
		return (NULL);
	field->str = str_new(tmp);
	field->flags = str_new(ft_memset(tmp, flag, ft_strlen(content)));
	free(tmp);
	return (field);
}
