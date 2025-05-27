/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:16:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 08:43:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_setenv(const char *name, const char *value, int overwrite)
{
	t_arr	*envp;
	int		i;
	int		len;

	if (!name)
		return (-1);
	envp = g_mish.envp;
	if (!envp)
		return (-1);
	i = -1;
	len = ft_strlen(name);
	while (++i < envp->index)
	{
		if (ft_strncmp((char *)(envp->content[i]), name, len) == 0
			&& (((char *)(envp->content[i]))[len]) == '=')
		{
			if (!overwrite)
				return (0);
			arr_del_item(envp, i);
			break ;
		}
	}
	arr_append(envp, ft_strjoin(name, value, "="));
	return (0);
}
