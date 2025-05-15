/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_field.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:56:12 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 21:12:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef T_FIELD_H
# define T_FIELD_H

#include "./container.h"

typedef struct s_field {
  t_str *str;
  t_str *flags;
} t_field;

t_field	*field_new_empty(size_t size);
t_field	*field_new(char *content, int flag);
int	field_append(t_field *field, char c, int flag);
int	field_append_list(t_field *field, char *l, int flag);
void	field_clean(t_field **field);
void	field_empty(t_field *field);
char	*field_extract(t_field **field);
int	field_insert(t_field *field, size_t at, char *txt, int tag);
int field_drop_item(t_field *field, size_t at_index);
int field_drop_list(t_field *field, size_t from, size_t to);
int field_flags_set(t_field *field, size_t at_index, int c);


# endif 
