/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:34:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/16 17:08:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "./ft_linked_lst.h"
# include "./t_bool.h"

// Struct
typedef struct s_adr_info
{
	void	*adr;
	int		tag;
	void	(*del)(void *);
}			t_adr_info;

// this ft_malloc
void		*ft_malloc(size_t size, t_list **list, int tag,
				void (*del)(void *));
// free tag
t_bool		ft_free_tag(t_list **lst, int tag);
// Free All Tags
t_bool		ft_free_all_tags(t_list **lst);

void		*ft_nad(void *ptr, t_list **list);
void		*ft_ad(void *ptr, t_list **list, int tag, void (*del)(void *));

#endif
