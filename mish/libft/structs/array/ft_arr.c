/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdenasse <abdenasse@student.1337.ma>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:34:56 by abdenasse          #+#    #+#            */
/*   Updated: 2025/05/03 21:35:45 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

t_arr	*arr_new(void)
{
	t_arr	*arr;

	arr = ft_calloc(1, sizeof(t_arr));
	if (!arr)
		return (NULL);
	arr->index = 0;
	arr->size = 2;
	arr->content = ft_calloc(arr->size, sizeof(void *));
	if (!(arr->content))
		return (NULL);
	return (arr);
}

int	arr_append(void *ptr)
{
	return (0);
}
