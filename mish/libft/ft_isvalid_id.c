/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:53:30 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/20 18:29:31 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

// valid id is id contain just alphanum or _ and doesn't start with digit
int	ft_isvalid_id(char *id)
{
	if (!id || ft_isdigit(*id))
		return (0);
	while (*++id)
		if (!ft_isalnum(*id) && *id != '_')
			return (0);
	return (1);
}
