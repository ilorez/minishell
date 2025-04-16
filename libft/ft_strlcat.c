/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:11:13 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/11 09:59:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	_ft_strncat(char *dest, const char *src, size_t nb, size_t dl)
{
	size_t	j;

	j = 0;
	while (src[j] && j < nb)
	{
		dest[dl + j] = src[j];
		j++;
	}
	dest[dl + j] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_p_src_len;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && src && !size)
		return (src_len);
	dest_len = ft_strlen(dst);
	dest_p_src_len = dest_len + src_len;
	if (size <= dest_len)
		return (size + src_len);
	_ft_strncat(dst, src, (size - dest_len - 1), dest_len);
	return (dest_p_src_len);
}

/*size_t original_strlcat(char *dst, const char *src, size_t size) {
	size_t dst_len = strlen(dst);
	size_t src_len = strlen(src);

	if (size <= dst_len) {
		return (size + src_len);
	}

	size_t to_copy = size - dst_len - 1;
	if (to_copy > src_len) {
		to_copy = src_len;
	}

	strncat(dst, src, to_copy);
	return (dst_len + src_len);
}

int	main(int ac, char **av)
{
	char *src = av[1];
	char dst[15];
	char dst2[15];
	int i;

	i = 0;
	while (av[2][i])
	{
		dst[i] = av[2][i];
		dst2[i] = av[2][i];
		i++;
	}
	dst[i] = '\0';
	dst2[i] = '\0';
	printf("my_string: %s\nmy_dst: %s\n", src, dst);
	ft_strlcat(dst, src, atoi(av[3]));
	printf("========= my function =========\nmy_string: %s\nmy_dst: %s\n", src,
		dst);
	original_strlcat(dst2, src, atoi(av[3]));
	printf("========= original function =========\nmy_string: %s\nmy_dst: %s\n",
		src, dst2);
	return (ac);
}*/

/*int main()
{
  char *src = " world";
  char *dst = NULL;

  //size_t res = strlen(dst) + strlen(src);
  size_t result = ft_strlcat(dst, src, 0);

 // printf("dst: %s\n", dst);
  //printf("res value: %zu\n", res);
  printf("result value: %zu\n", result);

}*/
