/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:40:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/18 20:32:35 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

// exit 
//  - free all data and exit
//  - it's ignore opetion but not argument
void ft_exit(char **argv, t_data *data)
{
  int status;

  if (!argv || !*argv)
    status = mish.exit_status;
  else if (!ft_is_valid_num(*argv))
      return (ft_ref_perror("exit", *argv, ERR_NONUM));
  else if (*(argv+1))
    return (ft_ref_perror("exit", NULL, ERR_TO_MANY_ARG));
  ft_waitpids(data->wpids);
  status = atoi(*argv);
  ft_free_all(data);
  exit(status);
}
