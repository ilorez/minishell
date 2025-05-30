/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:40:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 08:43:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_getenv(const char *name)
{
	char	*r;
	char	**envp;
	int		len;

	envp = (char **)(g_mish.envp)->content;
	if (!envp || !*envp)
		return (NULL);
	r = NULL;
	len = ft_strlen(name);
	while (*envp)
	{
		if (ft_strncmp(*envp, name, len) == 0 && *(*envp + len) == '=')
		{
			r = (*envp + len + 1);
			break ;
		}
		envp++;
	}
	return (r);
}
