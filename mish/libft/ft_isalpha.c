/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 07:23:09 by znajdaou          #+#    #+#             */
/*   Updated: 2024/10/22 07:56:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isalpha(int c)
{
	if (c < 65 || c > 122 || (c > 90 && c < 97))
	{
		return (0);
	}
	return (1);
}

/*
int	main(int argc, char *argv[])
{
	int		i;
	char	c;

	i = 0;
	while (i < argc)
	{
		c = ft_isalpha(argv[i][0]) + 48;
		write(1,&c , 1);
		i++;
	}
}
*/
