/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:04:07 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/18 18:05:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

int ft_unsetenv(const char *name)
{
  t_arr *envp;
  int i;
  int len;

  if (!name)
    return (-1);
  envp = mish.envp;
  if (!envp)
		  return (-1);
  i = -1;
  len = ft_strlen(name);
	while (++i < envp->index)
	{
		if (ft_strncmp((char *)(envp->content[i]), name, len) == 0 && (((char *)(envp->content[i]))[len]) == '=')
		{
      arr_del_item(envp, i);
      break;
		}
	}
	return (0);
}
