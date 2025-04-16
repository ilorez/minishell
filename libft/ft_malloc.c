/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:02:24 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/09 11:22:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_malloc(size_t size, t_list **list, int tag, void (*del)(void *))
{
	void		*ptr;
	t_list		*newnode;
	t_adr_info	*adr_info;

	if (!del || !list)
		return (NULL);
	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	adr_info = ft_calloc(1, sizeof(t_adr_info));
	adr_info->adr = ptr;
	adr_info->tag = tag;
	adr_info->del = del;
	newnode = ft_lstnew(adr_info);
	if (!newnode)
		return (free(ptr), free(adr_info), NULL);
	ft_lstadd_back(list, newnode);
	return (ptr);
}

void	*ft_ad(void *ptr, t_list **list, int tag, void (*del)(void *))
{
	t_list		*newnode;
	t_adr_info	*adr_info;

	if (!del || !list | !ptr)
		return (NULL);
	adr_info = ft_calloc(1, sizeof(t_adr_info));
	adr_info->adr = ptr;
	adr_info->tag = tag;
	adr_info->del = del;
	newnode = ft_lstnew(adr_info);
	if (!newnode)
		return (free(ptr), free(adr_info), NULL);
	ft_lstadd_back(list, newnode);
	return (ptr);
}

void	*ft_nad(void *ptr, t_list **list)
{
	t_list		*newnode;
	t_adr_info	*adr_info;

	if (!list | !ptr)
		return (NULL);
	adr_info = ft_calloc(1, sizeof(t_adr_info));
	adr_info->adr = ptr;
	adr_info->tag = 0;
	adr_info->del = free;
	newnode = ft_lstnew(adr_info);
	if (!newnode)
		return (free(ptr), free(adr_info), NULL);
	ft_lstadd_back(list, newnode);
	return (ptr);
}

t_bool	ft_free_tag(t_list **lst, int tag)
{
	t_adr_info	*adr_info;
	t_list		*tmp;
	t_list		*new_lst;

	if (!lst)
		return (0);
	new_lst = NULL;
	while (*lst)
	{
		adr_info = (t_adr_info *)((*lst)->content);
		tmp = *lst;
		if (adr_info->tag == tag)
		{
			adr_info->del(adr_info->adr);
			free(adr_info);
			*lst = (*lst)->next;
			free(tmp);
			continue ;
		}
		*lst = (*lst)->next;
		tmp->next = NULL;
		ft_lstadd_back(&new_lst, tmp);
	}
	*lst = new_lst;
	return (1);
}

t_bool	ft_free_all_tags(t_list **lst)
{
	t_adr_info	*adr_info;
	t_list		*tmp;

	if (!lst)
		return (0);
	while (*lst)
	{
		tmp = *lst;
		adr_info = (t_adr_info *)((*lst)->content);
		adr_info->del(adr_info->adr);
		free(adr_info);
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
	return (1);
}
