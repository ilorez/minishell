/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:59:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/09 10:47:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/* ft_strndup
 * this function is used to duplicate a substring
 * @param s: the string that we will duplicate
 * @param len: the length of the substring
 * @return: the address of the duplicated substring
 * @return: NULL if the string is empty
 **/
char	*ft_strndup(char const *s, size_t len)
{
	char	*ss;

	ss = (char *)ft_calloc(sizeof(char), len + 1);
	if (!ss)
		return (NULL);
	ss[len] = '\0';
	while (len--)
		ss[len] = s[len];
	return (ss);
}
