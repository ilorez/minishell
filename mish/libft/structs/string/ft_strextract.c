/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:25:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 12:33:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// extract value 
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

// extract copy of value
char	*str_extract_copy(t_str *str)
{
	if (!str)
		return (NULL);
	return (ft_strdup(str->value));
}

