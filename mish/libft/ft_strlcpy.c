/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:51 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/07 15:50:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize)
	{
		while (src[len] && --dstsize)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}

/*int main(int ac, char **av)
{
	size_t	dstlen;
	dstlen = atoi(av[2]);
	char	str2[dstlen];
	char	str3[dstlen];
	size_t	len;
	size_t	len_original;

	len = ft_strlcpy(NULL, av[1], 0);
	len_original = strlcpy(NULL, av[1], 0);
	printf ("str: %s,\nstrlcpy:%s\n", av[1], str2);
	printf ("original ------\nstr: %s,\nstrlcpy:%s", av[1], str3 );
	return (ac);
}*/
