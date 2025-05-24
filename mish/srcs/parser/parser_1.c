/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:13:56 by abdnasse          #+#    #+#             */
/*   Updated: 2025/05/14 19:36:13 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_ast	*parse_word(t_token **lst)
{
	t_arr	*exec;
	char	*arg;
	int		done;

	if (match(lst, T_LPAR))
		return (parse_list(lst));
	exec = arr_new();
	done = 0;
	while (match(lst, T_WORD) || match(lst, T_UNKNOWN))
	{
		if (match(lst, T_WORD))
		{
			arg = (char *)malloc(((*lst)->word->len + 1) * sizeof(char));
			if (!arg)
				exit_err("malloc failed", 2);
			ft_strlcpy(arg, (*lst)->word->ptr, (*lst)->word->len + 1);
			arr_append(exec, arg);
			next_token(lst);
			done++;
			done++;
		}
		next_token(lst);
	}
	if (done)
		return (new_node(T_EXEC, exec->content, NULL, NULL));
	return (NULL);
}

t_ast	*parse_list(t_token **lst)
{
	t_ast	*left;

	next_token(lst);
	left = parse_or_and(lst);
	next_token(lst);
	return (new_node(T_SUBSH, NULL, NULL, left));
}
