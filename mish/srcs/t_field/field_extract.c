/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 15:46:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

// extract the value
char	*field_extract(t_field **field)
{
	char	*tmp;

	if (!field || !*field)
	{
		return (NULL);
	}
	tmp = str_extract(&((*field)->str));
	str_clean(&((*field)->flags));
	free(*field);
	*field = NULL;
	return (tmp);
}

char	*field_extract_copy(t_field *field)
{
	if (!field)
	{
		return (NULL);
	}
	return (str_extract_copy(field->str));
}
