#ifndef T_DEBUG_H
# define T_DEBUG_H

# include "../includes/container.h"
# include <stdio.h>
void	print_token_type(t_token *token);
void	print_tokens(t_token *tk);
void	print_ast(t_ast *node, int level);

#endif
