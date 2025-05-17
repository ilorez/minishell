/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:18:25 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/16 16:40:31 by znajdaou         ###   ########.fr       */
/*                                 https://github.com/ilorez/minishell/pull/57/conflict?name=mish%252Fincludes%252Fcontainer.h&ancestor_oid=9722325057d5695170f236375d5b9a228acdf830&base_oid=04803ef2e8d27c9576878af2aebd1bd0328bd86a&head_oid=a626dd3a57cc3af9c97d27c508a7e6e26c5567f6                                           */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

// includes
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>


# include "../libft/includes/libft.h"
// THIS SHOULD BE ABOVE ALL THE HEADER CUZ IT CONTAINS ALL THE DATA TYPES
# include "./types.h"
# include "./parser.h"
# include "./t_field.h"
# include "./utils.h"
# include "./executor.h"
# include "./lexer.h"

#endif
