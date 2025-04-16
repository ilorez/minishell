/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:15:44 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/16 17:10:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

long long	_ft_max_as_signe(int signe)
{
	if (signe == 1)
		return (LLONG_MAX);
	return (LLONG_MIN);
}

/*
 * ft_atol,
 * function converts the initial portion of the string
 * pointed to by nptr to intis function
 *
 * @return: long long integer
 * on case of overflow return LLONG_MAX or LLONG_MIN dependent on signe
 *
 * */
long long	ft_atol(const char *nptr)
{
	size_t					i;
	int						signe;
	unsigned long long int	re;

	i = 0;
	signe = 1;
	re = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			signe = -1;
	while (ft_isdigit(nptr[i]))
	{
		if (re > (unsigned long long int)((LLONG_MAX - (nptr[i] - 48)) / 10))
			return (_ft_max_as_signe(signe));
		re = re * 10 + (nptr[i++] - 48);
	}
	return (re * signe);
}

/*#include <stdio.h>

int	main(void) {
	printf("llong MAX: %lld\n", ft_atol("9223372036854775807"));
	printf("llong MIN: %lld\n", ft_atol("-9223372036854775808"));
	printf("a number: %lld\n", ft_atol("922"));
	printf("a number: %lld\n", ft_atol("922000000000000000000000000000000000"));
	printf("a number: %lld\n", ft_atol("-922"));
	printf("a number: %lld\n",
		ft_atol("-922000000000000000000000000000000000"));
	printf("unsigned long long max: %lld\n", ft_atol("18446744073709551615"));
	printf("unsigned long long min: %lld\n", ft_atol("-18446744073709551616"));
	printf("unsigned long long min: %lld\n",
		ft_atol("-1844674407370955161000"));
	return (0);
}*/
