/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:43:27 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/12 11:31:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/libft.h"

/* ft_strjoin
 * this function is used to concatenate two strings
 * @param s1: the first string
 * @param s2: the second string
* @param c: the characters to be added between the two strings
 * @return: the address of the concatenated string
 * @return: s1 if s2 is NULL and vice versa || if both are NULL return ""

	* @note: the funciton always return a new allocated string
  * or null that can always be freed
 **/

char	*ft_strjoin(char const *s1, char const *s2, char const *c)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
	{
		return (ft_strdup(s2));
	}
	if (!s1 && !s2)
		return (ft_strdup(""));
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(c) + 1;
	dst = ft_calloc(sizeof(char), size);
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (c && *c)
		dst[i++] = *c++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}
