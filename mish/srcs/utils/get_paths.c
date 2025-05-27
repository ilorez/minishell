/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:43:26 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 08:43:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

// get paths & split it from envp
char	**ft_getpaths(void)
{
	char	**paths;
	char	**envp;

	if (!g_mish.envp)
		return (NULL);
	envp = (char **)(g_mish.envp)->content;
	if (!envp || !*envp)
		return (ft_split("", ' '));
	paths = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			paths = ft_split((*envp + 5), ':');
			break ;
		}
		envp++;
	}
	if (!paths)
		paths = ft_split("", ' ');
	return (paths);
}
