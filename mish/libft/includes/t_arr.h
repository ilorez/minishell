/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdenasse <abdenasse@student.1337.ma>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:36:32 by abdenasse          #+#    #+#            */
/*   Updated: 2025/05/13 20:47:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARR_H
# define T_ARR_H

typedef struct s_arr
{
	void	**content;
	int		index; // writing index pointed on the last item
  int i; // index
	int		size;
	void	(*clean)(void *);
}			t_arr;

t_arr		*arr_new(void);
int			arr_append(t_arr *arr, void *ptr);
int			arr_del_item(t_arr *arr, int index);
void		arr_free(t_arr *arr);
void	arr_empty(t_arr *arr);
t_arr	*arr_merge(t_arr *arr1, t_arr *arr2);
void	**arr_extract(t_arr **arr);

#endif
