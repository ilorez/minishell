/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:39:33 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 10:52:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildins.h"

// Mark each name to be passed to child
//        processes in the environment.
// the names refer to shell variables not  functions.
// If no names are supplied,
//        a list of names of all exported variables is displayed.
// If a variable name is followed by =value,
//        the value of the variable is set to value.
// The return status is zero unless
//        an invalid option is supplied,
// one of the names is not a valid shell variable name
// https://www.gnu.org/software/bash/manual/bash\
//        .html?utm_source=chatgpt.com#Shell-Parameters

int	ft_export(char **argv)
{
	char	*value;

	int (i), (status) = 0;
	if (!argv || !*argv)
		return (ft_env(argv));
	i = -1;
	while (argv[++i])
	{
		value = ft_strchr(argv[i], '=');
		if (value)
			*value = 0;
		if (!ft_isvalid_id(argv[i]) || !argv[i][0])
		{
			if (value)
				*value = '=';
			ft_ref_perror("export", argv[i], ERR_IDENT);
			status = 1;
			continue ;
		}
		if (value)
			ft_setenv(argv[i], (value + 1), 1);
		else
			ft_setenv(argv[i], "", 1);
	}
	return (status);
}
