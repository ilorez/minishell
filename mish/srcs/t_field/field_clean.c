#include "../../includes/t_field.h"

void	field_clean(t_field **field)
{
	if (!field || !*field)
  {
		return ;
  }
  str_clean(&((*field)->str));
  str_clean(&((*field)->flags));
  free(*field);
	*field = NULL;
}

void	field_empty(t_field *field)
{
	if (!field)
  {
		return ;
  }
  str_empty(field->str);
  str_empty(field->flags);
}
