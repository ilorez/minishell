/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:00:19 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/14 14:42:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/* check_null_terminate
 * note: work just if *c_point is not null
 * */
static void	_check_null_terminate(char **c_point)
{
	if (!**c_point)
	{
		free(*c_point);
		*c_point = NULL;
	}
}

/* _cut_line
 * this function is used to extract the line from the readed value
 * and update update c_point by removing the line that we read
 * @param c_point: the readed value
 * @param line: the line that we read
 * @return: void
 * #Note: this function is static and can be used only in this file
 **/
static void	_cut_line(char **c_point, char **line)
{
	size_t	i;
	char	*tmp;

	if (!**c_point)
	{
		_check_null_terminate(c_point);
		*line = NULL;
		return ;
	}
	i = 0;
	while ((*c_point)[i] && (*c_point)[i] != '\n')
		i++;
	if (!(*c_point)[i])
	{
		*line = ft_strdup(*c_point);
		free((*c_point));
		*c_point = NULL;
		return ;
	}
	*line = (ft_strndup(*c_point, i + 1));
	tmp = *c_point;
	*c_point = ft_strdup(&(*c_point)[i + 1]);
	free(tmp);
	if (*c_point)
		_check_null_terminate(c_point);
}

/* _search_for_line
 * this function is used to read from file descriptor untel found "\n" or EOF
 * @param fd: file descriptor
 * @param c_point: the readed value
 * @param buffer: the buffer that we will use to read from file descriptor
 * @return: the readed value
 * @return: NULL if error || EOF || empty file || malloc failed
	|| BUFFER_SIZE <= 0 || fd < 0 || read failed || read return 0
 * #Note: this function is static and can be used only in this file
 **/
static char	*_search_for_line(int fd, char *c_point, char *buffer)
{
	ssize_t	readed;
	char	*tmp;
	char	*found_line;

	found_line = NULL;
	while (!found_line)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == 0)
			break ;
		if (readed < 0)
			return (NULL);
		buffer[readed] = '\0';
		found_line = ft_strchr(buffer, '\n');
		tmp = c_point;
		c_point = ft_strjoin(c_point, buffer, "");
		free(tmp);
	}
	return (c_point);
}

/* get_next_line
 * The objective of this function is to read a line from a file descriptor
 * by reading BUFFER_SIZE bytes from fd file untel found "\n" or EOF
 * @param fd: file descriptor
 * @return: the line that we read from file
 * @return: NULL if error || EOF || empty file || malloc failed
	|| BUFFER_SIZE <= 0 || fd < 0 || read failed || read return 0
 **/
char	*get_next_line(int fd)
{
	static char	*c_point;
	char		*line;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(c_point, '\n'))
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		c_point = _search_for_line(fd, c_point, buffer);
		if (!c_point)
		{
			free(buffer);
			return (NULL);
		}
	}
	_cut_line(&c_point, &line);
	free(buffer);
	return (line);
}
