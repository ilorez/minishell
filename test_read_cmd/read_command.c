
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

// fd
typedef struct s_fd {
  enum {
    IN,
    OUT,
    OUTAPPEND
  } type;
  char *text; // path | EOF
} t_fd;

// string
typedef struct s_string
{
  char *value;
  size_t size;
  size_t used;
  size_t index;
} t_string;

// simple command
typedef struct s_simple_cmd {
	t_string *cmd;
	t_string *args;
  t_fd **fd_list; // those at begining and end of command with it's order
} t_simple_cmd;

// tag for quotes
typedef enum s_tag{
  NONE,
  DOUBLE_Q,
  SINGLE_Q
} t_tag;

///////////////////////////////////////////////////////
/// for string
///////////////////////////////////////////////////////

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize)
	{
		while (src[len] && --dstsize)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*nb;
	size_t			i;

	i = 0;
	nb = (unsigned char *)b;
	while (i < len)
		nb[i++] = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t;
	void	*ptr;

	if (size != 0 && (count > ((size_t)-1 / size)))
		return (NULL);
	t = count * size;
	ptr = malloc(t);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, t);
	return (ptr);
}

// expand string
void ft_string_expand(t_string *str, size_t size)
{
  char *tmp;
  if (!str)
    return ;
  tmp = ft_calloc(size + str->size + 1, 1);
  if (!tmp)
    return ;
  ft_strlcpy(tmp, str->value, str->size + size + 1);
  free(str->value);
  str->value = tmp;
}

// append to string
void ft_string_append(t_string *str, char c)
{
  if (!str)
    return;
  if (str->size - str->used == 0)
    ft_string_expand(str, 10);
  str->value[str->index++] = c;
  str->value[str->index] = 0;
  str->used++;
}

// create string
t_string *ft_create_empty_str(size_t size)
{
  t_string *str;

  str = ft_calloc(sizeof(t_string), 1);
  if (!str)
    return (NULL);
  str->value = ft_calloc(size + 1, 1);
  if (!str->value)
    return (free(str), NULL);
  str->size = size;
  str->value[0] = 0;
  return (str);
}
///////////////////////////////////////////////////////
/// DONE => for string
///////////////////////////////////////////////////////

// is space
int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

// is delmiter " ' | || && > <
int ft_isdelimiter(char c)
{
  if (c == '\'' || c == '"')
    return 1;
  return 0;
}

// get simple cmd
// example: ls hello
t_simple_cmd *get_simple_cmd(char *txt)
{
  t_tag tag;
  t_simple_cmd *full_cmd;
  t_string *args;
  t_string *curr;

  full_cmd = ft_calloc(sizeof(t_simple_cmd), 1);
  full_cmd->cmd = ft_create_empty_str(1);
  if (!full_cmd->cmd)
    return NULL;
  args = ft_create_empty_str(1);
  if (!args)
    return NULL;


  curr = full_cmd->cmd;
  tag = NONE;
  while (*txt)
  {
    while (!tag && curr != args && ft_isspace(*txt))
      txt++;

    while (tag)
    {
      if ((*txt == '\'' && tag == SINGLE_Q) || (*txt == '"' && tag == DOUBLE_Q))
        tag = NONE;
      else
        ft_string_append(curr, *txt);
      txt++;
    }

    while (*txt && !ft_isdelimiter(*txt))
    {
        if (ft_isspace(*txt) && curr != args)
        {
          curr = args;
          txt++;
          continue;
        }
        ft_string_append(curr, *txt);
        txt++;
    }

    if (*txt == '\'')
      tag = SINGLE_Q;
    else if (*txt == '"')
      tag = DOUBLE_Q;
    if (*txt)
      txt++;
  }
  // split it later
  full_cmd->args = args;
  return  full_cmd;
}

void print_simple_cmd(t_simple_cmd *cmd)
{
  if (!cmd)
    printf("Error: cmd Empty");
  printf("cmd: %s\n", cmd->cmd->value);
  printf("args: %s\n", cmd->args->value);
}

int main()
{
  char *input;
  //rl_clear_history();
  while (1)
  {
    input = readline("command>");
    if (!input) break;
    if (*input)
    {
      add_history(input);
      print_simple_cmd(get_simple_cmd(input));
    }
  }
  return (0);
}

