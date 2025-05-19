/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:29:25 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/19 16:17:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDINS_H 
#define BUILDINS_H

#include "./container.h"
#include <linux/limits.h>

// buildins utils
int ft_run_buildin(t_buildin b, char **argv, t_data *data);
t_buildin ft_is_buildin(char *path);

// buildins
int ft_echo(char **argv);
int ft_cd(char **argv);
int ft_env(char **argv);
int ft_pwd(char **argv);
int ft_unset(char **argv);
void ft_exit(char **argv, t_data *data);
int ft_export(char **argv);

#endif 
