

#ifndef	HEADER_H
#define HEADER_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <aio.h>
#include "type.h"
#include "string.h"


cmd	*root;
void	ft_parse_line(char	*buffer);
void	ft_next_token(void);
cmd		*ft_parse_list(void);
cmd		*ft_parse_cmd(void);
cmd		*ft_new_node(t_token op,char *value, cmd *l, cmd *r);

#endif
