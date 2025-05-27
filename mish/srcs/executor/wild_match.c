/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:45:04 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/21 08:40:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

static t_arr	*_get_match(t_arr *wild, DIR *dir);
static int		_is_match(t_arr *wild, char *name);
static int		_find_word(char *name, int *i, char *word);

t_arr	*ft_wild_match(t_arr *wild)
{
	DIR		*dir_ptr;
	t_arr	*match_list;

	if (!wild)
		return (NULL);
	dir_ptr = opendir(".");
	if (!dir_ptr)
	{
		perror("Can't open dir");
		return (NULL);
	}
	match_list = _get_match(wild, dir_ptr);
	if (!match_list)
		return (NULL);
	if (closedir(dir_ptr))
	{
		perror("Can't close dir");
		return (NULL);
	}
	arr_free(wild);
	return (match_list);
}

static t_arr	*_get_match(t_arr *wild, DIR *dir)
{
	t_arr			*mlst;
	struct dirent	*dir_read;

	mlst = arr_new();
	if (!mlst)
		return (NULL);
	dir_read = readdir(dir);
	while (dir_read)
	{
		if (dir_read->d_name[0] == '.' && **(char **)(wild->content) != '.')
			;
		else if (!_is_match(wild, dir_read->d_name))
			arr_append(mlst, ft_strdup(dir_read->d_name));
		dir_read = readdir(dir);
	}
	return (mlst);
}

static int	_find_word(char *name, int *i, char *word)
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

static int	_is_match(t_arr *wild, char *name)
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
		if (!_find_word(name, &i, parts[++j]))
			return (1);
	}
	else if (strncmp(name, parts[0], strlen(parts[0])))
		return (1);
	while (++j < wild->index)
		if (!_find_word(name, &i, parts[j]))
			return (1);
	i = strlen(name) - strlen(parts[j - 1]);
	if (parts[j - 1][0] == 0)
		return (0);
	else if (name[i] != 0 && !_find_word(name, &i, parts[j - 1]))
		return (1);
	return (0);
}
