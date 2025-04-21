/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:57:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/21 17:08:44 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRING_H 
#define	STRING_H 

#include <stdlib.h>

// string
typedef struct s_string
{
  char *value;
  size_t size;
  size_t used;
  size_t index;
} t_string;

void ft_string_expand(t_string *str, size_t size);
void ft_string_append(t_string *str, char c);
t_string *ft_create_empty_str(size_t size);

#endif // !DEBUG
