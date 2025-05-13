/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:55:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/11 23:38:10 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// expand string
static int	_str_expand(t_str *str, size_t size)
{
	char	*tmp;

	if (!str)
		return (0);
	tmp = ft_calloc(size + str->size + 1, 1);
	if (!tmp)
		return (0);
	str->size += size + 1;
	ft_strlcpy(tmp, str->value, str->size);
	free(str->value);
	str->value = tmp;
	return (1);
}

// append to string
// <null-terminated> not included in str->size
int	str_append(t_str *str, char c)
{
	if (!str)
		return (0);
	if (str->size <= str->_wi)
		if (!_str_expand(str, str->size / 2))
			return (0);
	str->value[str->_wi++] = c;
	str->value[str->_wi] = 0;
	return (1);
}

int	str_append_list(t_str *str, char *list)
{
	size_t	len;

	if (!str || !list)
		return (0);
	len = ft_strlen(list);
	if (str->size - str->_wi <= len)
		if (!_str_expand(str, str->size / 2 + len))
			return (0);
	len = 0;
	while (list[len])
	{
		str->value[str->_wi + len] = list[len];
		len++;
	}
	str->_wi += len;
	str->value[str->_wi] = 0;
	return (1);
}
