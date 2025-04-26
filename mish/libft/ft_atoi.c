/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:27:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/16 17:08:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/libft.h"

static int	_d_signe(int signe)
{
	if (signe == 1)
		return (-1);
	return (0);
}

static int	_ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t				i;
	int					signe;
	unsigned long long	re;
	unsigned long long	max;

	max = 9223372036854775807;
	i = 0;
	signe = 1;
	re = 0;
	while (_ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			signe = -1;
	while (ft_isdigit(nptr[i]))
	{
		if (re > (max - (nptr[i] - 48)) / 10)
			return (_d_signe(signe));
		re = re * 10 + (nptr[i++] - 48);
	}
	return ((int)(re * signe));
}

/*
  int main(int ac, char   **av)
{
	if (ac == 2)
	{
		int res = atoi(av[1]);
		printf("atoi: %d\n", res);
		int res1 = ft_atoi(av[1]);
		printf("ft_atoi: %d\n", res1);
	}
	return (0);
}*/
