/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdenasse <abdenasse@student.1337.ma>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:36:32 by abdenasse          #+#    #+#            */
/*   Updated: 2025/05/16 15:44:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARR_H
# define T_ARR_H

// index: writing index pointed on the last item
typedef struct s_arr
{
	void	**content;
	int		index;
	int		i;
	int		size;
	void	(*clean)(void *);
}			t_arr;

t_arr		*arr_new(void);
int			arr_append(t_arr *arr, void *ptr);
int			arr_del_item(t_arr *arr, int index);
void		arr_empty(t_arr *arr);
t_arr		*arr_merge(t_arr *arr1, t_arr *arr2);
void		**arr_extract(t_arr **arr);
void		arr_free(void *ptr);
void		arr_clean(t_arr **arr);
void		arr_free_body(t_arr *arr);

#endif
