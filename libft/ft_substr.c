/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:23:41 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/31 11:51:06 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ss;

	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
	{
		ss = (char *)(ft_calloc(1, sizeof(char)));
		if (!ss)
			return (NULL);
		ss[0] = '\0';
		return (ss);
	}
	size = 0;
	size = ft_strlen((char *)(s + start));
	if (size > len)
		size = len;
	ss = (char *)ft_calloc(sizeof(char), size + 1);
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, (char *)(s + start), size + 1);
	return (ss);
}

/*int main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%s\n", ft_substr(av[1], atoi(av[2]), atoi(av[3])));
		// original function
		// printf("%s\n", substr(av[1], atoi(av[2]), atoi(av[3])));
	}
	return (0);
}*/
