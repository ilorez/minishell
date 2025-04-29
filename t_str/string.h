/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:57:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/28 15:07:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRING_H 
#define	STRING_H 

// includes
#include "../mish/libft/includes/libft.h"

// struct
typedef struct s_str
{
  char *value;
  size_t size;
  size_t i; // index
  size_t _wi; // write index
} t_str;

t_str *str_new(char *content);
t_str *str_new_empty(size_t size);
int str_append(t_str *str, char c);
void str_clean(t_str **str);
//size_t str_len(t_str str);

#endif // !DEBUG
