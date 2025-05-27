/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:06:07 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/21 08:15:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

// includes
# include "./container.h"

// functions
int				ft_setup_mish(int ac, char **av, char **envp);
t_data			*ft_setup_data(t_data *data, t_ast *ast);

// global var
extern t_mish	g_mish;

#endif
