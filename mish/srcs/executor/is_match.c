/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:45:04 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/13 21:30:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

static int	find_word(char *name, int *i, char *word)
{
	int	j;

	if (!*word)
		return (1);
	while (name[*i])
	{
		j = 0;
		while (word[j] && name[*i + j] == word[j])
			j++;
		if (!*(word + j))
		{
			*i = *i + j;
			return (1);
		}
		(*i)++;
	}
	return (0);
}

int	_is_match(t_arr *wild, char *name)
{
	int		i;
	int		j;
	char	**parts;

	parts = (char **)wild->content;
	i = 0;
	j = 0;
	if (wild->index == 1 && parts[0][0] == 0)
		return (0);
	if (parts[0][0] == 0)
	{
		if (!find_word(name, &i, parts[++j]))
			return (1);
	}
	else if (strncmp(name, parts[0], strlen(parts[0])))
		return (1);
	while (++j < wild->index)
		if (!find_word(name, &i, parts[j]))
			return (1);
	i = strlen(name) - strlen(parts[j - 1]);
	if (parts[j - 1][0] == 0)
		return (0);
	else if (name[i] != 0 && !find_word(name, &i, parts[j - 1]))
		return (1);
	return (0);
}
