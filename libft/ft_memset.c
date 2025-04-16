/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:33:59 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/07 10:14:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*nb;
	size_t			i;

	i = 0;
	nb = (unsigned char *)b;
	while (i < len)
		nb[i++] = (unsigned char)c;
	return (b);
}
