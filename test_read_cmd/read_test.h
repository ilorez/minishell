/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:57:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/16 17:58:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_TEST_H
#define READ_TEST_H

#include "../libft/includes/libft.h"

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
