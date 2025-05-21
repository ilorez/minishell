/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:16:07 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 08:43:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	exit_err(char *msg, t_errno code)
{
	ft_perror(msg, code);
	exit(code);
}

void	ft_handel_exit(t_data *data, int status)
{
	ft_free_all(&data);
	exit(status);
}
