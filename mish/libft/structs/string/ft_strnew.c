/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/03 21:10:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// create empty string
t_str	*str_new_empty(size_t size)
{
	t_str	*str;

	str = ft_calloc(sizeof(t_str), 1);
	if (!str)
		return (NULL);
	if (size < 4)
		size = 4;
	str->value = ft_calloc(size + 1, 1);
	if (!str->value)
		return (free(str), NULL);
	str->size = size;
	str->value[0] = 0;
	return (str);
}

// create string
t_str	*str_new(char *content)
{
	t_str	*str;

	str = ft_calloc(sizeof(t_str), 1);
	if (!str)
		return (NULL);
	str->size = ft_strlen(content);
	str->_wi = str->size;
	if (str->size < 4)
		str->size = 4;
	str->value = ft_calloc(str->size + 1, 1);
	if (!str->value)
		return (free(str), NULL);
	ft_strlcpy(str->value, content, str->size + 1);
	return (str);
}
