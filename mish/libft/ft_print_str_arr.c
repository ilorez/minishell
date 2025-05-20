/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:32:51 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/17 18:37:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_print_str_arr(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = -1;
	while (arr[++i])
	{
		ft_putstr_fd(arr[i], STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
	}
}
