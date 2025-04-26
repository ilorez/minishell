/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:28:45 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/09 16:23:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*udst;
	const unsigned char	*usrc;

	if (dst == src)
		return (dst);
	udst = (unsigned char *)dst;
	usrc = (const unsigned char *)src;
	i = -1;
	if (udst > usrc)
		while (++i < len)
			*(udst + len - i - 1) = *(usrc + len - i - 1);
	else
		while (++i < len)
			*(udst + i) = *(usrc + i);
	return (dst);
}

/*#include <string.h>
int	main(void)
{
  //char str1[] = "hi";
  char *str1 = NULL;
  char *str2 = "hi";
	printf("edit: %s\n", (char *)ft_memmove(str2 ,str1, 2));
	//printf("original: %s\nafter Edit: %s", str, (char *)memmove(str1 ,str2,
			5));
}*/
