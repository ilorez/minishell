#include "../../includes/t_field.h"

// str clean
char	*field_extract(t_field **field)
{
	char	*tmp;

	if (!field || !*field)
  {
		return (NULL);
  }
  tmp = str_extract(&((*field)->str));
  str_clean(&((*field)->flags));
  free(*field);
  *field = NULL;
	return (tmp);
}
