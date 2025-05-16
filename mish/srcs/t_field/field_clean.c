/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 15:46:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_field.h"

void	field_clean(t_field **field)
{
	if (!field || !*field)
	{
		return ;
	}
	str_clean(&((*field)->str));
	str_clean(&((*field)->flags));
	free(*field);
	*field = NULL;
}

void	field_free(void *ptr)
{
	t_field	*field;

	field = (t_field *)ptr;
	if (!field)
	{
		return ;
	}
	str_free(field->str);
	str_free(field->flags);
	free(field);
}

void	field_empty(t_field *field)
{
	if (!field)
	{
		return ;
	}
	str_empty(field->str);
	str_empty(field->flags);
}
