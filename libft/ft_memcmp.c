/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:58:14 by znajdaou          #+#    #+#             */
/*   Updated: 2024/10/26 09:37:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (us1[i] != us2[i])
			return ((int)(us1[i] - us2[i]));
	return (0);
}

/*int main(int ac, char **av)
{

	char *str1;
	str1 = av[1];
	char *str2;
	str2 = av[2];
	int diff = (int)ft_memcmp((const void *)str1,(const void *)str2,atoi(av[3]));
	int diff2 = (int)memcmp((const void *)str1,(const void *)str2,atoi(av[3]));
	printf("str1:%s\nstr2:%s\ndeferent byte:%d\n", str1, str2, diff);
	printf("oringinal deferent byte:%d\n", diff2);
	return (ac);
}*/
