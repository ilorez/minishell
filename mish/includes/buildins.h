/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:29:25 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/18 20:30:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDINS_H 
#define BUILDINS_H

#include "./container.h"
#include <linux/limits.h>

int ft_echo(char **argv);
int ft_cd(char **argv);
int ft_env(char **argv);
int ft_pwd(char **argv);
int ft_unset(char **argv);
void ft_exit(char **argv, t_data *data);

#endif 
