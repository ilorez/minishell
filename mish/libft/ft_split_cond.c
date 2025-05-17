/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cond.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/15 19:38:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/libft.h"

static size_t	_ft_c_ws(char const *str, int (f)(int))
{
	size_t	i;
	size_t	w;

	w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && f(str[i]))
			i++;
		if (str[i])
			w++;
		while (str[i] && !f(str[i]))
			i++;
	}
	return (w);
}

static void	*_ft_free_words(char **strs, size_t i)
{
	while (i--)
		free(strs[i]);
	free(strs);
	return (NULL);
}

static void	_ft_skip(int not, char const *s, size_t *i, int (f)(int))
{
	if (not)
		while (*(s + *i) && !f(*(s + *i)))
			(*i)++;
	else
		while (*(s + *i) && f(*(s + *i)))
			(*i)++;
	return ;
}

static char	**_get_splited(char const *s, int (f)(int), char **strings)
{
	char	*word;
	char	*start;
	size_t	i;
	size_t	w_i;

	i = 0;
	w_i = 0;
	while (*(s + i))
	{
		_ft_skip(0, s, &i, f);
		if (*(s + i))
		{
			start = (char *)(s + i);
			_ft_skip(1, s, &i, f);
			word = ft_substr(s, start - s, (s + i) - start);
			if (!word)
				return (_ft_free_words(strings, w_i));
			strings[w_i++] = word;
		}
	}
	strings[w_i] = 0;
	return (strings);
}

char	**ft_split_cond(char const *s, int (f)(int))
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = (char **)ft_calloc(sizeof(char *), (_ft_c_ws(s, f) + 1));
	if (!strings)
		return (NULL);
	return (_get_splited(s, f, strings));
}
