/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randtmpfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:00:01 by znajdaou          #+#    #+#             */
/*   Updated: 2025/06/01 15:00:21 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_randtmp_file(char *dir, char *prefix)
{
	char	*random;
	char	*path;

	random = ft_itoa((unsigned long)(&tmpfile));
	if (!random)
		return (NULL);
	path = ft_strjoin(dir, random, prefix);
	free(random);
	return (path);
}
