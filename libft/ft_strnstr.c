/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:39:18 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/03 10:22:10 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (!needle[j + 1])
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

// original main
/*char *strnstr(const char *s, const char *find, size_t slen)
{
	size_t	len;

	char c, sc;
	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}



int	main(void)
{
  // test 1 - testing


  //char *str1 = ft_strdup("hello");
  //char *str2 = NULL;
  //char *f_at = ft_strnstr((const char *)str1, (const char *)str2, 0 );
  //char *o_f_at = strnstr((const char *)str1, (const char *)str2, 0);
  //ft_strnstr((const char *)str1, (const char *)str2, 0 );
  //strnstr((const char *)str1, (const char *)str2, 0);
	//printf("str1: %s\nstr2: %s\nfounded at:%s\noriginal founded at:%s\n",
		str1, str2, f_at, o_f_at);

	return (0);
}*/
