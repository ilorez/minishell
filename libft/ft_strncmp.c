/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:30:18 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/12 15:46:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s2[i] || s1[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
  ft_strncmp(NULL, NULL, 0);
}*/
/*int main(int ac, char **av)
{
	printf("str1:%s\nstr2:%s\nretuned:%d\n", av[1], av[2], ft_strncmp(av[1],
			av[2], atoi(av[3])));
	return (ac);
}*/
