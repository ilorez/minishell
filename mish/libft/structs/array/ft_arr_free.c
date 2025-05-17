/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:14:22 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 10:50:49 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	arr_free(void *ptr)
{
	int		i;
	t_arr	*arr;

	arr = ptr;
	if (!arr)
		return ;
	if (arr->content)
	{
		i = -1;
		while (++i < arr->index)
			if (arr->clean && arr->content[i])
				arr->clean(arr->content[i]);
		free(arr->content);
	}
	free(arr);
}

void	arr_clean(t_arr **arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	if ((*arr)->content)
	{
		i = -1;
		while (++i < (*arr)->index)
			if ((*arr)->clean && (*arr)->content[i])
				(*arr)->clean((*arr)->content[i]);
		free((*arr)->content);
	}
	free(*arr);
	*arr = NULL;
}

void	arr_free_body(t_arr *arr)
{
	if (!arr)
		return ;
	if (arr->content)
		free(arr->content);
	free(arr);
}

void	arr_empty(t_arr *arr)
{
	int	i;

	if (!arr)
		return ;
	if (arr->content)
	{
		i = -1;
		while (++i < arr->index)
		{
			if (arr->clean && arr->content[i])
				arr->clean(arr->content[i]);
			arr->content[i] = NULL;
		}
	}
	arr->index = 0;
}
