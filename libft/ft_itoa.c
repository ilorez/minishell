/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:27:50 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/31 11:37:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static size_t	_ft_count_digits(int nbr)
{
	size_t	i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	_ft_stock(int nbr, int *i, char *result)
{
	int	mod;

	if (nbr > 9)
		_ft_stock(nbr / 10, i, result);
	mod = nbr % 10 + 48;
	result[*i] = mod;
	(*i)++;
}

char	*ft_itoa(int n)
{
	size_t	malloc_s;
	int		signe;
	char	*result;
	int		i;

	i = 0;
	signe = 1;
	malloc_s = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		signe = -1;
		malloc_s += 1;
		n = -n;
	}
	malloc_s += _ft_count_digits(n);
	result = ft_calloc(sizeof(char), malloc_s);
	if (!result)
		return (NULL);
	if (signe == -1)
		result[i++] = '-';
	_ft_stock(n, &i, result);
	result[malloc_s - 1] = '\0';
	return (result);
}

/*int	main(int ac, char **av)
{
	printf("my string: %s\n", ft_itoa(ft_atoi(av[1])));
	return (ac);
}*/
