/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:19:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/22 19:30:49 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

/* this fucntion return 1 or 0
 * first it check if that is a normal termination
 *    - true
 *        [get exit status and update g_mish.exit_status]
 *        return (1)
 *    - flase
 *        [check if that signal is SIGINT] => set g_mish.exit_status = 130;
 *        [check core dump] => print core dumped
 *        return (0)
 *
*/ 


int ft_
