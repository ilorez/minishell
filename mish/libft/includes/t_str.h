/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:57:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 19:47:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STR_H
# define T_STR_H

// includes
# include "./libft.h"

// struct
typedef struct s_str
{
	char	*value;
	size_t	size;
	size_t	i;
	size_t	_wi;
}			t_str;

// _wi: write index points on null terminated

t_str		*str_new(char *content);
t_str		*str_new_empty(size_t size);
int			str_append(t_str *str, char c);
int			str_append_list(t_str *str, char *list);
void		str_clean(t_str **str);
char		*str_extract(t_str **str);
void	str_empty(t_str *str);
int str_insert(t_str *str, size_t at, char *text);
size_t str_len(t_str *str);

#endif
