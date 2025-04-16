/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:06:36 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/05 10:25:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	_ft_get_signe(const char **nptr, int *signe)
{
	if (**nptr == '-' || **nptr == '+')
		if (*(*nptr)++ == '-')
			*signe = -1;
}

double	ft_strtod(const char *nptr, char **endptr)
{
	unsigned long long	div;
	int					signe;
	double				re;

	signe = 1;
	div = 10;
	re = 0.0;
	if (!nptr)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	_ft_get_signe(&nptr, &signe);
	while (ft_isdigit(*nptr))
		re = re * 10 + (*nptr++ - '0');
	if (*nptr == '.')
		nptr++;
	while (ft_isdigit(*nptr) && div < LLONG_MAX)
	{
		re += (double)(*nptr++ - '0') / div;
		div *= 10;
	}
	if (*nptr && endptr)
		*endptr = (char *)nptr;
	return (re * signe);
}
