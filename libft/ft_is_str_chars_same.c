/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_chars_same.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:24:20 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/26 10:37:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_is_str_chars_same(char *str, char c)
{
	while (*str)
		if (*str++ != c)
			return (0);
	return (1);
}
