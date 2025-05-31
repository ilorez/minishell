/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:21:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 11:39:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static size_t	_ft_found_pre(char const *s1, char const *set)
{
	size_t	pre;

	pre = 0;
	while (s1[pre])
	{
		if (ft_strchr(set, s1[pre]))
			pre++;
		else
			break ;
	}
	return (pre);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	pre;
	size_t	suf;
	size_t	len;

	if (!set || !s1)
		return (NULL);
	suf = 0;
	len = ft_strlen(s1);
	pre = _ft_found_pre(s1, set);
	if (pre == len)
		return (ft_strdup(""));
	while (suf < len)
	{
		if (ft_strchr(set, s1[len - suf - 1]))
			suf++;
		else
			break ;
	}
	len = len - pre - suf;
	return (ft_substr(s1, pre, len));
}

/*int main(int argc, char *argv[])
{
  if (argc == 3)
  {
	printf("ft_strtrim:%s\nlen: %ld\n", ft_strtrim(argv[1], argv[2]),
		ft_strlen(ft_strtrim(argv[1], argv[2])));
	//printf("set is NULL:%s\n", ft_strtrim(argv[1], NULL));
	//printf("str is NULL:%s\n", ft_strtrim(NULL, argv[2]));
  }
  return (EXIT_SUCCESS);
}*/
