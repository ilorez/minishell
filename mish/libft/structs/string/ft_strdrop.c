/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:17:15 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 12:05:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// create empty string
int	str_drop_item(t_str *str, size_t at_index)
{
	char	*tmp;

	if (!str || str->_wi <= at_index)
		return (0);
	tmp = &str->value[at_index + 1];
	str->_wi = at_index;
	str_append_list(str, tmp);
	return (1);
}

int	str_drop_list(t_str *str, size_t from, size_t to)
{
	char	*tmp;

	if (!str || from >= to || str->_wi < to)
		return (0);
	tmp = &(str->value[to]);
	str->_wi = from;
	str_append_list(str, tmp);
	return (1);
}
