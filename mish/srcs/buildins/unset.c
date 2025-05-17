/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:01:34 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/17 19:09:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

int ft_unset(char **argv)
{
  int i;
  
  if (!argv || !*argv)
    return (0);
  i = -1;
  while (argv[++i])
    ;//TODO: ft_unset_var(argv[i]);
  return (0);
}
