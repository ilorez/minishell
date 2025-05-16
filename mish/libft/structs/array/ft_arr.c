/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdenasse <abdenasse@student.1337.ma>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:34:56 by abdenasse          #+#    #+#            */
/*   Updated: 2025/05/16 10:22:32 by znajdaou         ###   ########.fr       */
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
	arr->size = 10;
	arr->clean = free;
	arr->content = ft_calloc(arr->size, sizeof(void *));
	if (!(arr->content))
		return (free(arr), NULL);
	return (arr);
}

int	arr_append(t_arr *arr, void *ptr)
{
	void	**new;

	if (!arr || !ptr)
		return (0);
	if (arr->index >= arr->size)
	{
		arr->size += (arr->size / 2);
		new = ft_calloc(arr->size, sizeof(void *));
		if (!new)
			return (0);
		ft_memcpy(new, arr->content, arr->index * sizeof(void *));
		free(arr->content);
		arr->content = new;
	}
	arr->content[arr->index++] = ptr;
	return (1);
}

// del item at <index> and set the last item in arr in place of deleted item
int	arr_del_item(t_arr *arr, int index)
{
	if (!arr || index < 0 || index >= arr->index)
		return (0);
	if (arr->clean && arr->content[index])
		arr->clean(arr->content[index]);
	arr->content[index] = arr->content[arr->index - 1];
	arr->content[arr->index - 1] = 0;
	arr->index--;
	return (1);
}

void	**arr_extract(t_arr **arr)
{
	void	**r;

	if (!arr || !*arr)
		return (NULL);
	r = (*arr)->content;
	free(*arr);
	*arr = NULL;
	return (r);
}
