/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 23:43:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// str clean
void	str_clean(t_str **str)
{
	if (!str || !*str)
		return ;
	free((*str)->value);
	free(*str);
	*str = NULL;
}

// str free is str_clean by get just single pointer
void	str_free(void *ptr)
{
	t_str	*str;

	str = (t_str *)ptr;
	if (!str)
		return ;
	free(str->value);
	free(str);
}

// str empty or free value
void	str_empty(t_str *str)
{
	if (!str)
		return ;
	ft_bzero(str->value, str->_wi);
	str->i = 0;
	str->_wi = 0;
}
