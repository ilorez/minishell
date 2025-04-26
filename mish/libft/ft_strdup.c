/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:02:38 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/31 12:13:21 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/* ft_strdup
 * this function is used to duplicate a string
 * @param s1: the string that we will duplicate
 * @return: the address of the duplicated string
 * @return: NULL if the string is empty
 **/

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
