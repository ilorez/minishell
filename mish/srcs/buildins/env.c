/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:51:10 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/18 20:56:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

int ft_env(char **argv)
{
  if (argv && *argv)
  {
    ft_ref_perror("env", NULL, ERR_TO_MANY_ARG);
    return (1);
  }
  ft_print_str_arr((char **)(mish.envp->content));
  return (0);
}

