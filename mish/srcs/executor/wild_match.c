
#include "../../includes/container.h"
#include <dirent.h>
#include <stdio.h>

t_arr *_get_match(t_arr *wild, DIR *dir);
t_arr *ft_wild_match(t_arr *wild)
{
  DIR *dir_ptr;
  t_arr *match_list;
  
  if (!wild)
    return (NULL);
  dir_ptr = opendir(".");
  if (!dir_ptr)
  {
    perror("Can't open dir");
    return (NULL);
  }
  match_list = _get_match(wild, dir_ptr);
  if (!match_list)
    return (NULL);
  if (closedir(dir_ptr))
  {
    perror("Can't close dir");
    return (NULL);
  }
  arr_free(wild);
  return (match_list);
}

// TODO: is_match think about it
int _is_match(t_arr *wild, char *name)
{
  int i;
  int j;
  char **parts;

  parts = (char **)wild->content;
  i = 0;
  j = -1;
  while (parts[i][++j])
    if (parts[i][j] != *name)
      return (1);
  while (++i < wild->index)
  {


  }
  
  return (0);
}

t_arr *_get_match(t_arr *wild, DIR *dir)
{
  t_arr *mlst;
  struct dirent *dir_read;

  mlst = arr_new();
  if (mlst)
  {
    ft_perror(NULL, ERR_MALLOC_FAIL);
    return (NULL);
  }
  dir_read = readdir(dir);
  while (dir_read)
  {
    if (_is_match(wild, dir_read->d_name))
      arr_append(mlst, dir_read->d_name);
    dir_read = readdir(dir);
  }
  return (mlst);
}


int main()
{
  ft_wild_match(NULL);
}
