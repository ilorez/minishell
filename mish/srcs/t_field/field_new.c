#include  "../../includes/t_field.h"

t_field	*field_new_empty(size_t size)
{

  t_field *field;

  field = ft_calloc(1, sizeof(t_field));
  if (!field)
    return (NULL);

  field->str = str_new_empty(size);
  field->flags = str_new_empty(size);
  return (field);
}

t_field	*field_new(char *content, int flag)
{

  t_field *field;
  char *tmp;

  tmp = ft_strdup(content);
  field = ft_calloc(1, sizeof(t_field));
  if (!field)
    return (NULL);

  field->str = str_new(tmp);
  field->flags = str_new(ft_memset(tmp, flag, ft_strlen(content)));
  free(tmp);
  return field;
}
