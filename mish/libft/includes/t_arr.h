/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdenasse <abdenasse@student.1337.ma>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:36:32 by abdenasse          #+#    #+#            */
/*   Updated: 2025/05/03 21:39:59 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARR_H
# define T_ARR_H

typedef struct s_arr
{
	void	*content;
	int		index;
	int		size;
	void	(*clean)(void *);
}			t_arr;

t_arr		*arr_new(void);
int			arr_append(void *ptr);
int			arr_del_item(int index);
void		arr_free(t_arr *arr);

#endif
