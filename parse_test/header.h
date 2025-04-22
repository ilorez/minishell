

#ifndef	HEADER_H
#define HEADER_H

#include <readline/readline.h>
#include <readline/history.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <aio.h>

#include "type.h"
#include "string.h"

void	ft_parse_line(char	*buffer);
void	ft_next_token(void);
t_token	ft_get_token(char *ptr);
cmd		*ft_parse_list(void);
cmd		*ft_parse_cmd(void);
cmd		*ft_new_node(t_token op,char *value, cmd *l, cmd *r);

#endif
