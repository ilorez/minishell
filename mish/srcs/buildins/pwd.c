/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:48:41 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/17 19:00:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

int ft_pwd(char **argv)
{
  if (*argv && **argv)
  {
    ft_ref_perror("env", NULL, ERR_TO_MANY_ARG);
    return (1);
  }
  ft_putstr_fd(getenv("PWD"), STDOUT_FILENO);
  return (0);
}
