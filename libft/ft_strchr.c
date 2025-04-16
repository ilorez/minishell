/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:42:48 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/31 12:57:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/* ft_gnl_strchr
 * this function is used to search for a character in a string
 * @param s: the string that we will search in
 * @param c: the character that we will search for
 * @return: the address of the first occurence of the character in the string
 * @return: NULL if the character is not found
 * #Note: this function is static and can be used only in this file
 **/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] != (char)c)
		return (NULL);
	return ((char *)(&(s[i])));
}
