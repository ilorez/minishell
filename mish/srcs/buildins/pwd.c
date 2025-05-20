/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:48:41 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/20 18:37:11 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

//if (*argv && **argv)
//  {
//    ft_ref_perror("pwd", NULL, ERR_TO_MANY_ARG);
//    return (1);
//  }
int ft_pwd(char **argv)
{
  (void)argv;
  ft_putstr_fd(mish.cwd, STDOUT_FILENO);
  write(STDOUT_FILENO, "\n", 1);
  return (0);
}
