/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:37:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 08:58:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "libft.h"
#include "t_arr.h"

// flags
// 0: normal
// 1: inside quotes

static t_arr	*_wilds_expand(t_arr *fields, t_arr *args);
static t_arr	*_fields_expand(t_arr *fields);

char	**ft_extract(char **argv)
{
	char	*join;
	t_arr	*args;

	join = ft_strjoin_list((const char **)argv, " ");
	if (!join)
		return (ft_free_str_lst(argv), NULL);
	args = ft_extract_arg(join);
	free(join);
	if (!args)
		return (ft_free_str_lst(argv), NULL);
	return (ft_free_str_lst(argv), (char **)arr_extract(&args));
}

t_arr	*ft_extract_arg(char *arg)
{
	t_field	*field;
	t_arr	*fields;
	t_arr	*args;

	args = arr_new();
	if (!args)
		return (NULL);
	field = field_new(arg, '0');
	if (!field)
		return (arr_free(args), NULL);
	field_expand(field);
	fields = field_split(field, '0', ft_isspace);
	if (!fields)
		return (arr_free(args), field_free(field), NULL);
	return (_wilds_expand(fields, args));
}

// get all wildcard match of each field
// if there's no wild match for that field append field itself
static t_arr	*_wilds_expand(t_arr *fields, t_arr *args)
{
	t_arr	*wilds;
	char	*tmp;

	fields->i = -1;
	while (++(fields->i) < fields->index)
	{
		tmp = field_extract_copy(fields->content[fields->i]);
		wilds = field_split_char(fields->content[fields->i], '0', '*');
		if (wilds->index > 1)
		{
			wilds = _fields_expand(wilds);
			wilds = ft_wild_match(wilds);
			if (wilds->index)
			{
				args = arr_merge(args, wilds);
				free(tmp);
				continue ;
			}
		}
		arr_free(wilds);
		arr_append(args, tmp);
	}
	arr_free_body(fields);
	return (args);
}

// _fields_expand
// get extract the value of each field
// SUMMARY: conver field arr to str arr
static t_arr	*_fields_expand(t_arr *fields)
{
	t_field	*tmp;

	fields->i = -1;
	while (++fields->i < fields->index)
	{
		tmp = (t_field *)(fields->content[fields->i]);
		fields->content[fields->i] = field_extract(&tmp);
	}
	fields->clean = free;
	return (fields);
}
