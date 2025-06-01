/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:13:56 by abdnasse          #+#    #+#             */
/*   Updated: 2025/06/01 15:17:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"
#include "t_arr.h"
#include "t_errno.h"

t_ast	*parse_word(t_token **lst)
{
	t_arr	*exec;
	char	*arg;

	if (match(lst, T_LPAR))
		return (parse_list(lst));
	exec = arr_new();
	while (match(lst, T_WORD) || match_op(lst, 1))
	{
		if (match(lst, T_WORD))
		{
			arg = ft_calloc((*lst)->word->len + 1, sizeof(char));
			if (!arg)
				return (ft_perror("Error", ERR_MALLOC_FAIL), NULL);
			ft_strlcpy(arg, (*lst)->word->ptr, (*lst)->word->len + 1);
			arr_append(exec, arg);
			next_token(lst);
		}
		else
			*lst = (*lst)->next->next;
	}
	if (exec->index)
		return (new_node(T_EXEC, arr_extract(&exec), NULL, NULL));
	return ((arr_clean(&exec)), NULL);
}

t_ast	*parse_list(t_token **lst)
{
	t_ast	*left;

	next_token(lst);
	left = parse_or_and(lst);
	next_token(lst);
	return (new_node(T_SUBSH, NULL, NULL, left));
}
