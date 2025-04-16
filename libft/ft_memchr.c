/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:14:47 by znajdaou          #+#    #+#             */
/*   Updated: 2024/10/26 08:51:31 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*us;
	size_t			i;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (us[i] == uc)
			return ((void *)(s + i));
	return (NULL);
}

/*int main()
{
	char str[] = "hello world";
	char *ptr;
	ptr = (char *)ft_memchr( (const void *)str, '\0', 12);
	printf("str:%s\nhere is it:%s\n", str, ptr) ;


	printf("pointer:%p\nreal pointer:%p\n", ptr, (str+11));
}*/
