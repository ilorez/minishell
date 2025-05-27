/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:55:47 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/20 23:09:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// - merge arr1 and arr2 content 
// - update size and index to point in last item after merge
t_arr	*arr_merge(t_arr *arr1, t_arr *arr2)
{
	void	**new;

	if (arr1 && !arr2)
		return (arr1);
	if (!arr1 && arr2)
		return (arr2);
	if (!arr1)
		return (arr_new());
	if (arr1->index + arr2->index >= (arr1->size -1))
	{
		arr1->size += arr2->index + (arr1->size / 2);
		new = ft_calloc(arr1->size, sizeof(void *));
		if (!new)
			return (NULL);
		ft_memcpy(new, arr1->content, arr1->index * sizeof(void *));
		free(arr1->content);
		arr1->content = new;
	}
	ft_memcpy(&(arr1->content[arr1->index]), arr2->content, arr2->index
		* sizeof(void *));
	arr1->index += arr2->index;
	free(arr2->content);
	free(arr2);
	return (arr1);
}
