// this struct should change to handle this all this cases
// >file ==> type:out err:0 append:0
// &>file ==> type:out err:1 append:0
// >>file ==> type:out err:0 append:1
// &>>file ==> type:out err:1 append:1
// <file ==> type:in  append:0
// <<EOF (HERDOC) ==> type:in append:1 
// [number]>file ==> type:redirection  append:0
// [number]>>file ==> type:redirection append:1
// ...
typedef struct s_fd {
  enum {
    IN,
    OUT,
    HEREDOC,
    OUTAPPEND
  } type;
  t_bool err;
  t_bool append;
  int fd;
  char *path;
} t_fd; // no not like that


