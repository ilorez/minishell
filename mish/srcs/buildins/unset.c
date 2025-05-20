/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:01:34 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/20 18:52:15 by znajdaou         ###   ########.fr       */
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
    ft_unsetenv(argv[i]);
  return (0);
}
