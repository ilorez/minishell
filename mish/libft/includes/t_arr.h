

#ifndef T_STR_H
#define T_STR_H

typedef	struct s_arr{
	void	*content;
	int		index;
	int		size;
	void	(*clean)(void *);
} t_arr;

t_arr	*arr_new(void);
int		arr_append(void *ptr);
int		arr_del_item(int index);
void	arr_free(t_arr *arr);


#endif
