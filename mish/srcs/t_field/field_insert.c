
#include  "../../includes/t_field.h"


int	field_insert(t_field *field, size_t at, char *txt, int tag)
{
  if (!field || !txt)
    return (0);
  if (!str_insert(field->str, at, txt))
    return 0;
  if (!str_insert(field->str, at, ft_memset(txt, tag, ft_strlen(txt))))
    return (0);
  return (1);
}
