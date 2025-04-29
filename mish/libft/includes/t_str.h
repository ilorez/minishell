/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:57:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/29 15:24:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRING_H 
#define	STRING_H 

// includes
#include "./libft.h"

// struct
typedef struct s_str
{
  char *value;
  size_t size;
  size_t i; // read index
  size_t _wi; // write index points on null terminated
} t_str;

t_str *str_new(char *content);
t_str *str_new_empty(size_t size);
int str_append(t_str *str, char c);
int str_append_list(t_str *str, char *list);
void str_clean(t_str **str);
//size_t str_len(t_str str);

#endif // !DEBUG
