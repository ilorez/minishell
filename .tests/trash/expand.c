t_arr *ft_word_expansion(char *word)
{
  t_str *r;
  t_arr *wild;
  size_t start;

  r = str_new_empty(6);
  if (!r)
    return NULL;
  wild = arr_new();
  if (!wild)
    return (str_clean(&r), NULL);
  start = 0;
  while (*word)
  {
    if (*word == '\'')
      while (*++word != '\'' || (word++ && 0))
        str_append(r, *word);
    else if (*word == '"')
      _double_quote(r, &word);
    else if (*word == '$')
      _get_env(r, &word);
    else if (*word == '*')
    {
      if (start != r->_wi || !r->_wi) // so it's will count the serie of wilds as one wild
        arr_append(wild, ft_strdup(&(r->value[start])));
      str_append(r, *word++);
      start = r->_wi;
    }
    else
      str_append(r, *word++);
  }
  if (wild->index)
  {
      arr_append(wild, ft_strdup(&(r->value[start])));
      // get match files
      wild = ft_wild_match(wild);
      if (wild->index)
        return (str_clean(&r), wild);
  }
  arr_append(wild, str_extract(&r));
  return (wild);
}
