/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:16:07 by znajdaou          #+#    #+#             */
/*   Updated: 2025/06/01 15:16:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "t_errno.h"

void	ft_handel_exit(t_data *data, int status)
{
	ft_free_all(&data);
	rl_clear_history();
	exit(status);
}
