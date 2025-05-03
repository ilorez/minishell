/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/03 20:24:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/t_str.h"

// str clean
void	str_clean(t_str **str)
{
	if (!str || !*str)
		return ;
	free((*str)->value);
	free(*str);
	*str = NULL;
}
